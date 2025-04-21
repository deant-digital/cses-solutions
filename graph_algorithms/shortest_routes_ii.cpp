#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, q;
  cin >> n >> m >> q;
  vector<vector<ll>> dists(n + 1, vector<ll>(n + 1, LLONG_MAX));
  for (ll i = 1; i <= n; ++i) dists[i][i] = 0;
  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    dists[a][b] = min(dists[a][b], c);
    dists[b][a] = min(dists[b][a], c);
  }
  for (ll k = 1; k <= n; ++k) {
    for (ll i = 1; i <= n; ++i) {
      if (dists[i][k] == LLONG_MAX) continue;
      for (ll j = 1; j <= n; ++j) {
        if (dists[k][j] == LLONG_MAX) continue;
        if (dists[i][k] + dists[k][j] < dists[i][j]) {
          dists[i][j] = dists[i][k] + dists[k][j];
        }
      }
    }
  }
  while (q--) {
    ll a, b;
    cin >> a >> b;
    cout << (dists[a][b] == LLONG_MAX ? -1 : dists[a][b]) << '\n';
  }
}
