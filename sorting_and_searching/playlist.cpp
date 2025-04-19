#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  map<ll, ll> mp;
  ll ans = 0;
  for (ll l = 0, r = 0; r < n; ++r) {
    ++mp[vec[r]];
    while (mp[vec[r]] > 1) --mp[vec[l++]];
    ll len = r - l + 1;
    if (len > ans) ans = len;
  }
  cout << ans << '\n';
}
