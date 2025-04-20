#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s1, s2;
  cin >> s1 >> s2;
  vector<vector<ll>> dp(s1.size() + 1, vector<ll>(s2.size() + 1));
  for (ll i = 1; i <= s1.size(); ++i) dp[i][0] = i;
  for (ll i = 1; i <= s2.size(); ++i) dp[0][i] = i;
  for (ll i = 1; i <= s1.size(); ++i) {
    for (ll j = 1; j <= s2.size(); ++j) {
      if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
      else dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
    }
  }
  cout << dp[s1.size()][s2.size()] << '\n';
}
