#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

mat ops(const mat &a, const mat &b) {
  mat res(b.size(), vec(a[0].size(), LLONG_MAX));
  for (ll i = 0; i < b.size(); ++i) {
    for (ll j = 0; j < a[0].size(); ++j) {
      for (ll k = 0; k < a.size(); ++k) {
        if (a[k][j] == LLONG_MAX || b[i][k] == LLONG_MAX) continue;
        res[i][j] = min(res[i][j], a[k][j] + b[i][k]);
      }
    }
  }
  return res;
}

mat pow(mat a, ll n) {
  mat res(a.size(), vec(a.size(), LLONG_MAX));
  for (ll i = 0; i < a.size(); ++i) res[i][i] = 0;
  while (n) {
    if (n & 1) res = ops(res, a);
    a = ops(a, a);
    n >>= 1;
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;
  mat adj_mat(n + 1, vec(n + 1, LLONG_MAX));
  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    adj_mat[a][b] = min(adj_mat[a][b], c);
  }
  ll res = pow(adj_mat, k)[1][n];
  cout << (res == LLONG_MAX ? -1 : res) << '\n';
}
