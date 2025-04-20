#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<string> grid(n);
  for (auto &row : grid) cin >> row;
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
  dp[1][1] = 1;
  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= n; ++j) {
      if (grid[i - 1][j - 1] == '*') {
        dp[i][j] = 0;
        continue;
      }
      if (i == 1 && j == 1) continue;
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }
  }
  cout << dp[n][n] << '\n';
}
