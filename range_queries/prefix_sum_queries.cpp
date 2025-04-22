#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Seg {
  vector<pair<ll, ll>> tree;
  ll n;
  Seg(ll n) : tree(n << 1), n(n) {
  }
  Seg(vector<ll> vec) : Seg(vec.size()) {
    for (ll i = 0; i < n; ++i) tree[i + n] = {vec[i], max(0LL, vec[i])};
    for (ll i = n - 1; i; --i) {
      tree[i] = {tree[i << 1].first + tree[i << 1 | 1].first,
                 max(tree[i << 1].second,
                     tree[i << 1].first + tree[i << 1 | 1].second)};
    }
  }
  void update(ll i, ll x) {
    tree[i += n] = {x, max(0LL, x)};
    for (i >>= 1; i; i >>= 1) {
      tree[i] = {tree[i << 1].first + tree[i << 1 | 1].first,
                 max(tree[i << 1].second,
                     tree[i << 1].first + tree[i << 1 | 1].second)};
    }
  }
  ll query(ll l, ll r) {
    pair<ll, ll> p1, p2;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) {
        p1 = {p1.first + tree[l].first,
              max(p1.second, p1.first + tree[l].second)};
        ++l;
      }
      if (~r & 1) {
        p2 = {tree[r].first + p2.first,
              max(tree[r].second, tree[r].first + p2.second)};
        --r;
      }
    }
    return max(p1.second, p1.first + p2.second);
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
    ll type, a, b;
    cin >> type >> a >> b;
    if (type == 1) seg.update(a - 1, b);
    else cout << seg.query(a - 1, b - 1) << '\n';
  }
}
