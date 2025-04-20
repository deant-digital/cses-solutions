#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
  if (vec[0] == 0) {
    for (ll i = 1; i <= m; ++i) dp[1][i] = 1;
  } else dp[1][vec[0]] = 1;
  for (ll i = 2; i <= n; ++i) {
    for (ll j = 1; j <= m; ++j) {
      if (vec[i - 1] == 0 || vec[i - 1] == j) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
        if (j) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
        if (j < m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
      }
    }
  }
  ll ans = 0;
  for (ll i = 1; i <= m; ++i) ans = (ans + dp[n][i]) % MOD;
  cout << ans << '\n';
}
