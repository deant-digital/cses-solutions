#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  vector<vector<ll>> dp(n + 2, vector<ll>(n + 2));
  for (ll i = 1; i <= n; ++i) dp[i][i] = vec[i - 1];
  for (ll len = 2; len <= n; ++len) {
    for (ll l = 1; l + len - 1 <= n; ++l) {
      ll r = l + len - 1;
      dp[l][r] = max(vec[l - 1] + min(dp[l + 2][r], dp[l + 1][r - 1]),
                     vec[r - 1] + min(dp[l + 1][r - 1], dp[l][r - 2]));
    }
  }
  cout << dp[1][n] << '\n';
}
