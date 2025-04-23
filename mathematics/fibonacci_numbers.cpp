#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using vec = vector<ll>;
using mat = vector<vec>;

const ll MOD = 1e9 + 7;

mat mult(const mat &a, const mat &b) {
  mat res(b.size(), vec(a[0].size()));
  for (ll i = 0; i < b.size(); ++i) {
    for (ll j = 0; j < a[0].size(); ++j) {
      for (ll k = 0; k < a.size(); ++k) {
        res[i][j] = (res[i][j] + a[k][j] * b[i][k] % MOD) % MOD;
      }
    }
  }
  return res;
}

mat pow(mat a, ll n) {
  mat res(a.size(), vec(a.size()));
  for (ll i = 0; i < a.size(); ++i) res[i][i] = 1;
  while (n) {
    if (n & 1) res = mult(res, a);
    a = mult(a, a);
    n >>= 1;
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  if (n == 0 || n == 1) {
    cout << n << '\n';
    return 0;
  }
  mat t = {{0, 1}, {1, 1}};
  mat v = {{0, 1}};
  cout << mult(pow(t, n - 1), v)[0][1] << '\n';
}
