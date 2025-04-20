#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> dp(n + 1);
  dp[0] = 1;
  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= 6; ++j) {
      if (i - j < 0) break;
      dp[i] = (dp[i] + dp[i - j]) % MOD;
    }
  }
  cout << dp[n] << '\n';
}
