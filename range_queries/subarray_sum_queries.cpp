#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// sum, max sum, pre sum, post sum
using node = array<ll, 4>;

node merge(node &n1, node &n2) {
  ll sum = n1[0] + n2[0];
  ll pre = max({0LL, n1[2], n1[0] + n2[2], n1[0] + n2[0]});
  ll post = max({0LL, n2[3], n2[0] + n1[3], n1[0] + n2[0]});
  ll best = max({n1[1], n2[1], pre, post, n1[3] + n2[2]});
  return {sum, best, pre, post};
}

struct Seg {
  vector<node> tree;
  ll n = 1;
  Seg(ll _n) {
    while (n < _n) n <<= 1;
    tree.resize(n << 1);
  }
  Seg(vector<ll> vec) : Seg(vec.size()) {
    for (ll i = 0; i < vec.size(); ++i) {
      ll v = max(0LL, vec[i]);
      tree[i + n] = {vec[i], v, v, v};
    }
    build();
  }
  void build() {
    for (ll i = n - 1; i; --i) {
      tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
    }
  }
  void update(ll i, const node &x) {
    tree[i += n] = x;
    for (i >>= 1; i >= 1; i >>= 1) {
      tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
    }
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q;
  cin >> n >> q;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  Seg seg(vec);
  while (q--) {
    ll k, x;
    cin >> k >> x;
    ll v = max(0LL, x);
    seg.update(k - 1, {x, v, v, v});
    cout << max(0LL, seg.tree[1][1]) << '\n';
  }
}
