#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct BIT {
  vector<vector<ll>> tree;
  ll n, m;
  BIT(ll n, ll m) : tree(n + 1, vector<ll>(m + 1)), n(n), m(m) {
  }
  void update(ll i, ll j, ll x) {
    for (++i; i <= n; i += i & -i) {
      for (ll c = j + 1; c <= m; c += c & -c) tree[i][c] += x;
    }
  }
  ll query(ll i, ll j) {
    ll s = 0;
    for (++i; i; i -= i & -i) {
      for (ll c = j + 1; c; c -= c & -c) s += tree[i][c];
    }
    return s;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q;
  cin >> n >> q;
  vector<string> grid(n);
  for (auto& row : grid) cin >> row;
  BIT bit(n, n);
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < n; ++j) {
      if (grid[i][j] == '*') bit.update(i, j, 1);
    }
  }
  while (q--) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll x, y;
      cin >> x >> y;
      --x, --y;
      char& c = grid[x][y];
      if (c == '*') {
        bit.update(x, y, -1);
        c = '.';
      } else {
        bit.update(x, y, 1);
        c = '*';
      }
    } else {
      ll x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      --x1, --y1, --x2, --y2;
      cout << bit.query(x2, y2) - bit.query(x1 - 1, y2) -
                  bit.query(x2, y1 - 1) + bit.query(x1 - 1, y1 - 1)
           << '\n';
    }
  }
}
