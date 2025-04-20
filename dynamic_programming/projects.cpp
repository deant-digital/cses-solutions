#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<pair<pair<ll, ll>, ll>> vec(n);
  for (auto &[a, b] : vec) cin >> a.second >> a.first >> b;
  sort(vec.begin(), vec.end());
  vector<ll> dp(n + 1);
  for (ll i = 0; i < n; ++i) {
    dp[i + 1] = dp[i];
    auto it = lower_bound(
        vec.begin(), vec.end(), vec[i].first.second,
        [](auto &v1, auto value) { return v1.first.first < value; });
    ll cur = vec[i].second;
    if (it != vec.begin()) cur += dp[prev(it) - vec.begin() + 1];
    dp[i + 1] = max(dp[i + 1], cur);
  }
  cout << dp[n] << '\n';
}
