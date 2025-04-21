#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> adjs(n + 1);
  while (m--) {
    ll a, b;
    cin >> a >> b;
    adjs[a].push_back(b);
    adjs[b].push_back(a);
  }
  vector<ll> parents(n + 1);
  vector<bool> visited(n + 1);
  auto dfs = [&](auto &&self, ll n, ll p) -> bool {
    visited[n] = true;
    parents[n] = p;
    for (ll adj : adjs[n]) {
      if (adj == p) continue;
      if (visited[adj]) {
        vector<ll> path;
        path.push_back(adj);
        ll cur = n;
        while (cur != adj) {
          path.push_back(cur);
          cur = parents[cur];
        }
        path.push_back(adj);
        if (path.size() >= 3) {
          cout << path.size() << '\n';
          for (ll i = 0; i < path.size(); ++i) {
            if (i) cout << ' ';
            cout << path[i];
          }
          cout << '\n';
          return true;
        }
      } else if (self(self, adj, n)) return true;
    }
    return false;
  };
  for (ll i = 1; i <= n; ++i) {
    if (visited[i]) continue;
    if (dfs(dfs, i, 0)) return 0;
  }
  cout << "IMPOSSIBLE\n";
}
