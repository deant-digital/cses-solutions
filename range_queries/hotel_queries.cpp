#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Seg {
  vector<ll> tree;
  ll n;
  Seg(ll n) : tree(n << 1), n(n) {
  }
  Seg(vector<ll> vec) : Seg(vec.size()) {
    for (ll i = 0; i < n; ++i) tree[i + n] = vec[i];
    build();
  }
  void build() {
    for (ll i = n - 1; i; --i) tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
  }
  void set(ll i, ll x) {
    for (tree[i += n] = x; i > 1; i >>= 1) {
      tree[i >> 1] = max(tree[i], tree[i ^ 1]);
    }
  }
  void update(ll i, ll x) {
    set(i, tree[i + n] + x);
  }
  ll query(ll l, ll r) {
    ll ans = LLONG_MIN;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) ans = max(ans, tree[l++]);
      if (~r & 1) ans = max(ans, tree[r--]);
    }
    return ans;
  }
  ll find_first(ll x, ll l, ll r) {
    if (l == r) return tree[l + n] >= x ? l : -1;
    ll m = l + ((r - l) >> 1);
    ll mx1 = query(l, m);
    if (mx1 >= x) return find_first(x, l, m);
    ll mx2 = query(m + 1, r);
    if (mx2 >= x) return find_first(x, m + 1, r);
    return -1;
  }
  ll find_first(ll x) {
    return find_first(x, 0, n - 1);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  Seg seg(vec);
  for (ll i = 0; i < m; ++i) {
    ll x;
    cin >> x;
    ll idx = seg.find_first(x);
    if (idx != -1) seg.update(idx, -x);
    if (i) cout << ' ';
    cout << idx + 1;
  }
  cout << '\n';
}
