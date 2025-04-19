#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, x;
  cin >> n >> x;
  vector<ll> vec(n);
  for (ll &v : vec) cin >> v;
  map<ll, ll> mp{{0, 1}};
  ll s = 0;
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    s += vec[i];
    auto it = mp.find(s - x);
    if (it != mp.end()) ans += it->second;
    ++mp[s];
  }
  cout << ans << '\n';
}
