#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, t;
  cin >> n >> t;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  sort(vec.begin(), vec.end());
  ll l = 1;
  ll r = t * vec[0];
  while (l < r) {
    ll m = l + ((r - l) >> 1);
    ll v = 0;
    for (ll i = 0; i < n; ++i) v += m / vec[i];
    if (v >= t) r = m;
    else l = m + 1;
  }
  cout << l << '\n';
}
