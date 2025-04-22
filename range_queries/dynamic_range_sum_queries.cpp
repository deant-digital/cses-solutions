#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct BIT {
  vector<ll> tree, vec;
  BIT(ll n) : tree(n + 1), vec(n) {
  }
  void set(ll n, ll x) {
    point_update(n, x - vec[n]);
  }
  void point_update(ll n, ll x) {
    vec[n] += x;
    for (++n; n < tree.size(); n += n & -n) tree[n] += x;
  }
  ll query(ll n) {
    ll s = 0;
    for (++n; n; n -= n & -n) s += tree[n];
    return s;
  }
  ll query(ll l, ll r) {
    return query(r) - query(l - 1);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  BIT bit(n);
  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    bit.point_update(i, x);
  }
  while (m--) {
    ll t, a, b;
    cin >> t >> a >> b;
    if (t == 1) bit.set(a - 1, b);
    else cout << bit.query(a - 1, b - 1) << '\n';
  }
}
