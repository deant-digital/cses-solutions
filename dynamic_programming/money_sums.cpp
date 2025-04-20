#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  bitset<(ll)1e5 + 1> dp;
  dp[0] = true;
  while (n--) {
    ll x;
    cin >> x;
    for (ll i = (ll)1e5; i >= x; --i) {
      dp[i] = dp[i] | dp[i - x];
    }
  }
  vector<ll> ans;
  for (ll i = 1; i <= 1e5; ++i) {
    if (dp[i]) ans.push_back(i);
  }
  cout << ans.size() << '\n';
  for (ll i = 0; i < ans.size(); ++i) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  cout << '\n';
}
