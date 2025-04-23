#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

const ll MOD = 1e9 + 7;

mat mul(const mat &a, const mat &b) {
  mat res(b.size(), vec(a[0].size()));
  for (ll i = 0; i < b.size(); ++i) {
    for (ll j = 0; j < a[0].size(); ++j) {
      for (ll k = 0; k < a.size(); ++k) {
        res[i][j] = (res[i][j] + a[k][j] * b[i][k]) % MOD;
      }
    }
  }
  return res;
}

mat pow(mat a, ll n) {
  mat res(a.size(), vec(a.size()));
  for (ll i = 0; i < a.size(); ++i) res[i][i] = 1;
  while (n) {
    if (n & 1) res = mul(res, a);
    a = mul(a, a);
    n >>= 1;
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;
  mat adj_mat(n + 1, vec(n + 1));
  while (m--) {
    ll a, b;
    cin >> a >> b;
    ++adj_mat[a][b];
  }
  cout << pow(adj_mat, k)[1][n] << '\n';
}
