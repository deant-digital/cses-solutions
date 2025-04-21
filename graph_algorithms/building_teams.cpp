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
  vector<ll> teams(n + 1, 0);
  for (ll i = 1; i <= n; ++i) {
    if (teams[i] == 0) {
      teams[i] = 1;
      queue<ll> q;
      q.push(i);
      while (q.size()) {
        ll j = q.front();
        q.pop();
        for (ll adj : adjs[j]) {
          if (teams[adj] == 0) {
            teams[adj] = 3 - teams[j];
            q.push(adj);
          } else if (teams[adj] == teams[j]) {
            cout << "IMPOSSIBLE\n";
            return 0;
          }
        }
      }
    }
  }
  for (ll i = 1; i <= n; ++i) {
    if (i - 1) cout << ' ';
    cout << teams[i];
  }
  cout << '\n';
}
