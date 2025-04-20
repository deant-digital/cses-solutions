#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, x;
  cin >> n >> x;
  vector<ll> vec(n);
  for (ll &v : vec) cin >> v;
  vector<ll> dp(x + 1);
  dp[0] = 1;
  sort(vec.begin(), vec.end());
  for (ll i = 1; i <= x; ++i) {
    for (ll j = 0; j < n; ++j) {
      if (i - vec[j] < 0) break;
      dp[i] = (dp[i] + dp[i - vec[j]]) % MOD;
    }
  }
  cout << dp[x] << '\n';
}
