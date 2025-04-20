#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<array<ll, 2>> dp(1e6 + 1);
  dp[1][0] = 1;
  dp[1][1] = 1;
  for (ll i = 2; i <= 1e6; ++i) {
    dp[i][0] = (dp[i - 1][0] * 2 % MOD + dp[i - 1][1]) % MOD;
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 4 % MOD) % MOD;
  }
  while (n--) {
    ll x;
    cin >> x;
    cout << (dp[x][0] + dp[x][1]) % MOD << '\n';
  }
}
