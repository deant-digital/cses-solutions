#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, x;
  cin >> n >> x;
  vector<ll> vec(n);
  for (ll &v : vec) cin >> v;
  sort(vec.begin(), vec.end());
  vector<pair<ll, ll>> dp(1 << n);
  dp[0] = {1, 0};
  for (ll i = 1; i < 1LL << n; ++i) {
    dp[i] = {n, 0};
    for (ll j = 0; j < n; ++j) {
      if (i & 1LL << j) {
        auto cpy = dp[i ^ 1LL << j];
        if (cpy.second + vec[j] <= x) {
          cpy.second += vec[j];
        } else {
          ++cpy.first;
          cpy.second = vec[j];
        }
        dp[i] = min(dp[i], cpy);
      }
    }
  }
  cout << dp[(1 << n) - 1].first << '\n';
}
