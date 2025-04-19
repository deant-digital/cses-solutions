#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  ll l = 1, r = LLONG_MAX;
  auto valid = [&](ll m) {
    ll s = 0;
    ll c = 1;
    for (ll i = 0; i < n; ++i) {
      if (vec[i] > m) return false;
      if (s + vec[i] <= m) s += vec[i];
      else if (++c > k) return false;
      else s = vec[i];
    }
    return true;
  };
  while (l < r) {
    ll m = l + ((r - l) >> 1);
    if (valid(m)) r = m;
    else l = m + 1;
  }
  cout << l;
}
