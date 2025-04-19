#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<pair<ll, ll>> v(n);
  for (auto &[a, b] : v) cin >> b >> a;
  sort(v.begin(), v.end());
  ll ans = 1;
  ll last = v[0].first;
  for (ll i = 1; i < n; ++i) {
    if (last <= v[i].second) {
      ++ans;
      last = v[i].first;
    }
  }
  cout << ans << '\n';
}
