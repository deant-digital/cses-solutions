#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Seg {
  vector<ll> tree;
  ll n;
  Seg(ll n) : tree(n << 1, LLONG_MAX), n(n) {
  }
  void update(ll i, ll x) {
    for (tree[i += n] = x; i > 1; i >>= 1) {
      tree[i >> 1] = min(tree[i], tree[i ^ 1]);
    }
  }
  ll query(ll l, ll r) {
    ll ans = LLONG_MAX;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) ans = min(ans, tree[l++]);
      if (~r & 1) ans = min(ans, tree[r--]);
    }
    return ans;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q;
  cin >> n >> q;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  Seg seg1(n), seg2(n);
  for (ll i = 0; i < n; ++i) {
    seg1.update(i, vec[i] + i);
    seg2.update(i, vec[i] - i);
  }
  while (q--) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll k, x;
      cin >> k >> x;
      --k;
      seg1.update(k, x + k);
      seg2.update(k, x - k);
    } else {
      ll k;
      cin >> k;
      --k;
      cout << min(seg1.query(k, n - 1) - k, seg2.query(0, k) + k) << '\n';
    }
  }
}
