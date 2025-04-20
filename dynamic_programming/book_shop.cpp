#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, x;
  cin >> n >> x;
  vector<ll> h(n), s(n);
  for (auto &v : h) cin >> v;
  for (auto &v : s) cin >> v;
  vector<ll> dp(x + 1);
  for (ll i = 0; i < n; ++i) {
    for (ll j = x; j >= h[i]; --j) {
      dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
    }
  }
  cout << dp[x] << '\n';
}
