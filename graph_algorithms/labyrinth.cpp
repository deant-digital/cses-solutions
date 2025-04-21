#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (auto &row : grid) cin >> row;
  vector<vector<ll>> vis(n + 2, vector<ll>(m + 2));
  ll x1, y1, x2, y2;
  for (ll i = 0; i <= n + 1; ++i) vis[i][0] = vis[i][m + 1] = true;
  for (ll i = 0; i <= m + 1; ++i) vis[0][i] = vis[n + 1][i] = true;
  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= m; ++j) {
      if (grid[i - 1][j - 1] == '#') vis[i][j] = true;
      else if (grid[i - 1][j - 1] == 'A') x1 = i, y1 = j;
      else if (grid[i - 1][j - 1] == 'B') x2 = i, y2 = j;
    }
  }
  const ll dirs[5] = {0, 1, 0, -1, 0};  // RDLU
  const string dirstr = "RDLU";
  vector<vector<ll>> moves(n + 2, vector<ll>(m + 2));
  queue<pair<ll, ll>> q;
  q.push({x1, y1});
  vis[x1][y1] = true;
  while (q.size()) {
    auto [a, b] = q.front();
    q.pop();
    if (a == x2 && b == y2) {
      cout << "YES\n";
      ll ans = 0;
      string path;
      while (a != x1 || b != y1) {
        path += dirstr[moves[a][b]];
        ll cur = moves[a][b];
        a -= dirs[cur];
        b -= dirs[cur + 1];
      }
      reverse(path.begin(), path.end());
      cout << path.size() << '\n';
      cout << path << '\n';
      return 0;
    }
    for (ll i = 0; i < 4; ++i) {
      ll x = a + dirs[i];
      ll y = b + dirs[i + 1];
      if (vis[x][y]) continue;
      q.push({x, y});
      vis[x][y] = true;
      moves[x][y] = i;
    }
  }
  cout << "NO\n";
}
