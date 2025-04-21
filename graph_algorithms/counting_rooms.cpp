#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (string &row : grid) cin >> row;
  vector<vector<bool>> vis(n + 2, vector<bool>(m + 2));
  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= m; ++j) {
      if (grid[i - 1][j - 1] == '#') vis[i][j] = true;
    }
  }
  for (ll i = 0; i <= n + 1; ++i) vis[i][0] = vis[i][m + 1] = true;
  for (ll i = 0; i <= m + 1; ++i) vis[0][i] = vis[n + 1][i] = true;
  ll ans = 0;
  const ll dirs[5] = {0, 1, 0, -1, 0};
  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= m; ++j) {
      if (vis[i][j]) continue;
      ++ans;
      queue<pair<ll, ll>> q;
      q.push({i, j});
      vis[i][j] = true;
      while (q.size()) {
        auto [a, b] = q.front();
        q.pop();
        for (ll k = 0; k < 4; ++k) {
          ll x = a + dirs[k];
          ll y = b + dirs[k + 1];
          if (vis[x][y]) continue;
          vis[x][y] = true;
          q.push({x, y});
        }
      }
    }
  }
  cout << ans << '\n';
}
