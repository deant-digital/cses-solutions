#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (ll &v : vec) {
    cin >> v;
    v = (v % n + n) % n;
  }
  map<ll, ll> mp{{0, 1}};
  ll s = 0;
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    s = (s + vec[i]) % n;
    auto it = mp.find(s);
    if (it != mp.end()) ans += it->second;
    ++mp[s];
  }
  cout << ans << '\n';
}
