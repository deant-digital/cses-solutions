#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll a, b;
  cin >> a >> b;
  vector<vector<ll>> dp(a + 1, vector<ll>(b + 1, LLONG_MAX));
  for (ll i = 0; i <= a && i <= b; ++i) dp[i][i] = 0;
  for (ll i = 1; i <= a; ++i) {
    for (ll j = 1; j <= b; ++j) {
      if (i == j) continue;
      for (ll k = 1; k < i; ++k) {
        dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
      }
      for (ll k = 1; k < j; ++k) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
      }
    }
  }
  cout << dp[a][b] << '\n';
}
