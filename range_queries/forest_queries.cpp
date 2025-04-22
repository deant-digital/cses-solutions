#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (auto &row : grid) cin >> row;
  vector<vector<ll>> prefix(n + 1, vector<ll>(n + 1));
  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= n; ++j) {
      prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] -
                     prefix[i - 1][j - 1] + (grid[i - 1][j - 1] == '*');
    }
  }
  while (m--) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] +
                prefix[x1 - 1][y1 - 1]
         << '\n';
  }
}
