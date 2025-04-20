#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, x;
  cin >> n >> x;
  vector<ll> vec(n);
  for (ll &v : vec) cin >> v;
  vector<ll> dp(x + 1, LLONG_MAX);
  dp[0] = 0;
  sort(vec.begin(), vec.end());
  for (ll i = 1; i <= x; ++i) {
    for (ll j = 0; j < n; ++j) {
      if (i - vec[j] < 0) break;
      if (dp[i - vec[j]] == LLONG_MAX) continue;
      dp[i] = min(dp[i], dp[i - vec[j]] + 1);
    }
  }
  cout << (dp[x] == LLONG_MAX ? -1 : dp[x]) << '\n';
}
