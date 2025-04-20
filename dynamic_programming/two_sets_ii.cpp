#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  ll s = n * (n + 1) >> 1;
  if (s & 1) {
    cout << "0\n";
    return 0;
  }
  ll t = s >> 1;
  vector<ll> dp(t + 1);
  dp[0] = 1;
  for (ll i = 1; i <= n; ++i) {
    for (ll j = t; j >= i; --j) {
      dp[j] = (dp[j] + dp[j - i]) % MOD;
    }
  }
  cout << (dp[t] * ((ll)5e8 + 4)) % MOD << '\n';
}
