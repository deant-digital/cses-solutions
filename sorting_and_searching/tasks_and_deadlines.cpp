#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<pair<ll, ll>> vec(n);
  for (auto &[a, b] : vec) cin >> a >> b;
  sort(vec.begin(), vec.end());
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    if (i) vec[i].first += vec[i - 1].first;
    ans += vec[i].second - vec[i].first;
  }
  cout << ans;
}
