#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Seg {
  vector<ll> tree, lazy_set, lazy_add;
  ll size = 1;
  Seg(const vector<ll> &vec) {
    while (size < vec.size()) size <<= 1;
    tree.resize(size << 1);
    lazy_set.resize(size << 1);
    lazy_add.resize(size << 1);
    for (ll i = 0; i < vec.size(); ++i) tree[i + size] = vec[i];
    for (ll i = size - 1; i; --i) tree[i] = tree[i << 1] + tree[i << 1 | 1];
  }
  void push(ll i, ll len) {
    if (lazy_set[i]) {
      tree[i << 1] = lazy_set[i] * (len >> 1);
      tree[i << 1 | 1] = lazy_set[i] * (len >> 1);
      lazy_set[i << 1] = lazy_set[i];
      lazy_set[i << 1 | 1] = lazy_set[i];
      lazy_add[i << 1] = 0;
      lazy_add[i << 1 | 1] = 0;
      lazy_set[i] = 0;
    }
    if (lazy_add[i]) {
      tree[i << 1] += lazy_add[i] * (len >> 1);
      tree[i << 1 | 1] += lazy_add[i] * (len >> 1);
      lazy_add[i << 1] += lazy_add[i];
      lazy_add[i << 1 | 1] += lazy_add[i];
      lazy_add[i] = 0;
    }
  }
  void range_set(ll l, ll r, ll x, ll i = 1, ll nl = 0, ll nr = -1) {
    if (nr == -1) nr = size;
    if (nr <= l || r <= nl) return;
    if (l <= nl && nr <= r) {
      tree[i] = x * (nr - nl);
      lazy_set[i] = x;
      lazy_add[i] = 0;
      return;
    }
    push(i, nr - nl);
    ll m = nl + ((nr - nl) >> 1);
    range_set(l, r, x, i << 1, nl, m);
    range_set(l, r, x, i << 1 | 1, m, nr);
    tree[i] = tree[i << 1] + tree[i << 1 | 1];
  }
  void range_add(ll l, ll r, ll x, ll i = 1, ll nl = 0, ll nr = -1) {
    if (nr == -1) nr = size;
    if (nr <= l || r <= nl) return;
    if (l <= nl && nr <= r) {
      tree[i] += x * (nr - nl);
      lazy_add[i] += x;
      return;
    }
    push(i, nr - nl);
    ll m = nl + ((nr - nl) >> 1);
    range_add(l, r, x, i << 1, nl, m);
    range_add(l, r, x, i << 1 | 1, m, nr);
    tree[i] = tree[i << 1] + tree[i << 1 | 1];
  }
  ll range_query(ll l, ll r, ll i = 1, ll nl = 0, ll nr = -1) {
    if (nr == -1) nr = size;
    if (nr <= l || r <= nl) return 0;
    if (l <= nl && nr <= r) return tree[i];
    push(i, nr - nl);
    ll m = nl + ((nr - nl) >> 1);
    return range_query(l, r, i << 1, nl, m) +
           range_query(l, r, i << 1 | 1, m, nr);
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
    ll t;
    cin >> t;
    if (t == 1) {
      ll a, b, x;
      cin >> a >> b >> x;
      seg.range_add(a - 1, b, x);
    } else if (t == 2) {
      ll a, b, x;
      cin >> a >> b >> x;
      seg.range_set(a - 1, b, x);
    } else {
      ll a, b;
      cin >> a >> b;
      cout << seg.range_query(a - 1, b) << '\n';
    }
  }
}
