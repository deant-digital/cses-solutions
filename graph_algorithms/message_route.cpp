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
  queue<ll> q;
  q.push(1);
  vector<ll> prev(n + 1);
  prev[1] = 1;
  while (q.size()) {
    ll cur = q.front();
    q.pop();
    if (cur == n) {
      vector<ll> path;
      while (cur != 1) {
        path.push_back(cur);
        cur = prev[cur];
      }
      path.push_back(1);
      reverse(path.begin(), path.end());
      cout << path.size() << '\n';
      for (ll i = 0; i < path.size(); ++i) {
        if (i) cout << ' ';
        cout << path[i];
      }
      cout << '\n';
      return 0;
    }
    for (ll adj : adjs[cur]) {
      if (prev[adj]) continue;
      prev[adj] = cur;
      q.push(adj);
    }
  }
  cout << "IMPOSSIBLE\n";
}
