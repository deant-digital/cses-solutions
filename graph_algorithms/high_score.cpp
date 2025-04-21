#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> adjs(n + 1);
  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    adjs[a].push_back({b, c});
  }
  vector<ll> max_score(n + 1, LLONG_MIN);
  max_score[1] = 0;
  vector<bool> vis(n + 1);
  auto dfs = [&](auto &&self, ll idx) -> bool {
    if (vis[idx]) return false;
    vis[idx] = true;
    if (idx == n) return true;
    for (auto [adj, w] : adjs[idx]) {
      if (self(self, adj)) return true;
    }
    return false;
  };
  for (ll i = 0; i < n; ++i) {
    bool updated = false;
    for (ll j = 1; j <= n; ++j) {
      for (auto [adj, w] : adjs[j]) {
        if (max_score[j] == LLONG_MIN) continue;
        if (max_score[j] + w > max_score[adj]) {
          updated = true;
          max_score[adj] = max_score[j] + w;
          if (i == n - 1) {
            fill(vis.begin(), vis.end(), false);
            if (dfs(dfs, adj)) {
              cout << "-1\n";
              return 0;
            }
          }
        }
      }
    }
    if (!updated && i < n - 1) break;
  }
  cout << max_score[n] << '\n';
}
