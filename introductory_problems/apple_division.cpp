#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  ll ans = LLONG_MAX;
  for (ll i = 0; i < 1LL << n; ++i) {
    ll s1 = 0, s2 = 0;
    for (ll j = 0; j < n; ++j) {
      if (i & 1 << j) s1 += vec[j];
      else s2 += vec[j];
    }
    ans = min(ans, llabs(s1 - s2));
  }
  cout << ans << '\n';
}
