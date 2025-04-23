#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, a, b;
  cin >> n >> a >> b;
  vector<vector<double>> dp(n + 1, vector<double>(601));
  dp[0][0] = 1;
  for (ll i = 0; i < n; ++i) {
    for (ll j = 1; j <= 6; ++j) {
      for (ll k = i; k + j <= 6 * (i + 1); ++k) {
        dp[i + 1][k + j] += dp[i][k] / 6.0;
      }
    }
  }
  double ans = 0;
  for (ll i = n; i <= n * 6; ++i) {
    if (a <= i && i <= b) ans += dp[n][i];
  }
  cout << fixed << setprecision(6) << ans << '\n';
}
