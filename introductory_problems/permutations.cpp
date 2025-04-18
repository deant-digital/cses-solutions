#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  if (n <= 3) {
    cout << "NO SOLUTION\n";
    return 0;
  }
  vector<ll> ans;
  ans.reserve(n);
  for (ll i = 2; i <= n; i += 2) ans.push_back(i);
  for (ll i = 1; i <= n; i += 2) ans.push_back(i);
  for (ll i = 0; i < n; ++i) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  cout << '\n';
}
