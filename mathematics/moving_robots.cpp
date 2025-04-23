#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<vector<double>> vec(8, vector<double>(8, 1.0));
  const ll dirs[] = {0, 1, 0, -1, 0};
  for (ll i = 0; i < 8; ++i) {
    for (ll j = 0; j < 8; ++j) {
      vector<vector<double>> cur(8, vector<double>(8));
      vector<vector<double>> next(8, vector<double>(8));
      cur[i][j] = 1.0;
      for (ll k = 0; k < n; ++k) {
        for (auto &row : next) fill(row.begin(), row.end(), 0.0);
        for (ll a = 0; a < 8; ++a) {
          for (ll b = 0; b < 8; ++b) {
            vector<pair<ll, ll>> moves;
            for (ll c = 0; c < 4; ++c) {
              ll p = a + dirs[c];
              ll q = b + dirs[c + 1];
              if (p < 0 || q < 0 || p > 7 || q > 7) continue;
              moves.push_back({p, q});
            }
            double prob = cur[a][b] / moves.size();
            for (auto &[x, y] : moves) next[x][y] += prob;
          }
        }
        swap(cur, next);
      }
      for (ll a = 0; a < 8; ++a) {
        for (ll b = 0; b < 8; ++b) vec[a][b] *= 1.0 - cur[a][b];
      }
    }
  }
  double ans = 0.0;
  for (ll i = 0; i < 8; ++i) {
    for (ll j = 0; j < 8; ++j) ans += vec[i][j];
  }
  cout << fixed << setprecision(6) << ans << '\n';
}
