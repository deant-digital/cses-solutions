#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Seg {
  vector<ll> tree;
  ll n;
  Seg(ll n) : tree(n << 1, LLONG_MAX), n(n) {};
  void update(ll idx, ll val) {
    for (tree[idx += n] = val; idx; idx >>= 1) {
      tree[idx >> 1] = min(tree[idx], tree[idx ^ 1]);
    }
  }
  ll query(ll left, ll right) {
    ll mn = LLONG_MAX;
    for (left += n, right += n; left <= right; left >>= 1, right >>= 1) {
      if (left & 1) mn = min(mn, tree[left++]);
      if (~right & 1) mn = min(mn, tree[right--]);
    }
    return mn;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  Seg seg(n);
  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    seg.update(i, x);
  }
  while (m--) {
    ll t, a, b;
    cin >> t >> a >> b;
    if (t == 1) seg.update(a - 1, b);
    else cout << seg.query(a - 1, b - 1) << '\n';
  }
}
