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
  }
  vector<ll> parents(n + 1);
  vector<ll> states(n + 1);
  ll cycle_start = -1, cycle_end = -1;
  auto dfs = [&](auto &&self, ll n) -> bool {
    states[n] = 1;
    for (ll adj : adjs[n]) {
      if (states[adj] == 0) {
        parents[adj] = n;
        if (self(self, adj)) return true;
      } else if (states[adj] == 1) {
        cycle_start = adj;
        cycle_end = n;
        return true;
      }
    }
    states[n] = 2;
    return false;
  };
  for (ll i = 1; i <= n; ++i) {
    if (states[i] != 0) continue;
    if (dfs(dfs, i)) {
      vector<ll> path;
      ll cur = cycle_end;
      path.push_back(cycle_start);
      while (cur != cycle_start) {
        path.push_back(cur);
        cur = parents[cur];
      }
      path.push_back(cycle_start);
      cout << path.size() << '\n';
      for (ll i = path.size() - 1; i >= 0; --i) {
        cout << path[i];
        if (i) cout << ' ';
      }
      cout << '\n';
      return 0;
    }
  }
  cout << "IMPOSSIBLE\n";
}
