#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (auto &row : grid) cin >> row;
  vector<vector<ll>> min_dists(n + 1, vector<ll>(m + 1, LLONG_MAX));
  queue<tuple<ll, ll, ll>> monsters, players;
  vector<vector<ll>> vis(n + 2, vector<ll>(m + 2));
  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= m; ++j) {
      if (grid[i - 1][j - 1] == '#') vis[i][j] = true;
      else if (grid[i - 1][j - 1] == 'M') monsters.push({i, j, 0});
      else if (grid[i - 1][j - 1] == 'A') players.push({i, j, 0});
    }
  }
  for (ll i = 0; i <= n + 1; ++i) vis[i][0] = vis[i][m + 1] = true;
  for (ll i = 0; i <= m + 1; ++i) vis[0][i] = vis[n + 1][i] = true;
  vector<vector<ll>> vis2(vis.begin(), vis.end());
  const ll dirs[5] = {0, 1, 0, -1, 0};
  while (monsters.size()) {
    auto [x, y, z] = monsters.front();
    monsters.pop();
    if (vis[x][y]) continue;
    vis[x][y] = true;
    min_dists[x][y] = z;
    for (ll i = 0; i < 4; ++i) {
      monsters.push({x + dirs[i], y + dirs[i + 1], z + 1});
    }
  }
  vector<vector<ll>> moves(n + 1, vector<ll>(m + 1));
  ll startX = get<0>(players.front()), startY = get<1>(players.front());
  while (players.size()) {
    auto [x, y, z] = players.front();
    players.pop();
    if (vis2[x][y]) continue;
    vis2[x][y] = true;
    if (min_dists[x][y] <= z) continue;
    if (x == 1 || y == 1 || x == n || y == m) {
      cout << "YES\n";
      string path;
      string movestr = "RDLU";
      while (x != startX || y != startY) {
        ll cur = moves[x][y];
        x -= dirs[cur];
        y -= dirs[cur + 1];
        path += movestr[cur];
      }
      reverse(path.begin(), path.end());
      cout << path.size() << '\n';
      cout << path << '\n';
      return 0;
    }
    for (ll i = 0; i < 4; ++i) {
      ll x2 = x + dirs[i];
      ll y2 = y + dirs[i + 1];
      if (vis2[x2][y2]) continue;
      players.push({x2, y2, z + 1});
      moves[x2][y2] = i;
    }
  }
  cout << "NO\n";
}
