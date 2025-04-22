#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Node {
  ll sum_y;
  ll max_y;
  ll first_x;
};

struct Seg {
  const vector<ll> original;
  vector<Node> tree;
  ll size = 1;
  Seg(const vector<ll> &vec) : original(vec) {
    while (size < vec.size()) size <<= 1;
    tree.resize(size << 1);
    build(1, 0, size);
  }
  pair<ll, ll> eval(ll i, ll l, ll r, ll prev) {
    if (r - l == 1) {
      if (l < original.size()) {
        ll cur = max(original[l], prev);
        return {cur, cur};
      }
      return {0, prev};
    }
    ll m = l + ((r - l) >> 1);
    ll sl, ml, sr, mr;
    if (prev <= tree[i << 1].first_x) {
      sl = tree[i << 1].sum_y;
      ml = tree[i << 1].max_y;
    } else {
      auto [a, b] = eval(i << 1, l, m, prev);
      sl = a;
      ml = b;
    }
    if (ml <= tree[i << 1 | 1].first_x) {
      sr = tree[i << 1 | 1].sum_y;
      mr = tree[i << 1 | 1].max_y;
    } else {
      auto [a, b] = eval(i << 1 | 1, m, r, ml);
      sr = a;
      mr = b;
    }
    return {sl + sr, mr};
  }
  void build(ll i = 1, ll l = 0, ll r = -1) {
    if (r == -1) r = size;
    if (r - l == 1) {
      if (l < original.size())
        tree[i] = {original[l], original[l], original[l]};
      return;
    }
    ll m = l + ((r - l) >> 1);
    build(i << 1, l, m);
    build(i << 1 | 1, m, r);
    auto [a, b] = eval(i << 1 | 1, m, r, tree[i << 1].max_y);
    tree[i].sum_y = tree[i << 1].sum_y + a;
    tree[i].max_y = b;
    tree[i].first_x = tree[i << 1].first_x;
  }
  pair<ll, ll> query(ll l, ll r, ll i = 1, ll nl = 0, ll nr = -1, ll prev = 0) {
    if (nr == -1) nr = size;
    if (nr <= l || nl >= r) return {0, prev};
    if (l <= nl && nr <= r) return eval(i, nl, nr, prev);
    ll m = nl + ((nr - nl) >> 1);
    auto [sl, ml] = query(l, r, i << 1, nl, m, prev);
    auto [sr, mr] = query(l, r, i << 1 | 1, m, nr, ml);
    return {sl + sr, mr};
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q;
  cin >> n >> q;
  vector<ll> vec(n);
  vector<ll> prefix_sums(n + 1);
  for (ll i = 0; i < n; ++i) {
    cin >> vec[i];
    prefix_sums[i + 1] = prefix_sums[i] + vec[i];
  }
  Seg seg(vec);
  while (q--) {
    ll a, b;
    cin >> a >> b;
    cout << seg.query(a - 1, b).first - (prefix_sums[b] - prefix_sums[a - 1])
         << '\n';
  }
}
