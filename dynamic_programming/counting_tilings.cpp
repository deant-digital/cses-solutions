#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> dp(m + 1, vector<ll>(1LL << n));
  dp[0][0] = 1;
  for (ll i = 1; i <= m; ++i) {
    for (ll j = 0; j < 1LL << n; ++j) {
      queue<pair<ll, ll>> q;
      q.push({0, 0});
      while (q.size()) {
        auto [a, b] = q.front();
        q.pop();
        if (a == n) {
          dp[i][b] = (dp[i][b] + dp[i - 1][j]) % MOD;
          continue;
        }
        if (j & 1LL << a) {
          q.push({a + 1, b});
          continue;
        }
        q.push({a + 1, b | 1LL << a});
        if (a < n - 1 && ~j & 1LL << (a + 1)) q.push({a + 2, b});
      }
    }
  }
  cout << dp[m][0] << '\n';
}
