#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> dp(n + 1, LLONG_MAX);
  dp[0] = 0;
  for (ll i = 1; i <= n; ++i) {
    ll tmp = i;
    while (tmp > 0) {
      ll digit = tmp % 10;
      tmp /= 10;
      if (digit == 0) continue;
      if (i >= digit) dp[i] = min(dp[i], dp[i - digit] + 1);
    }
  }
  cout << dp[n] << '\n';
}
