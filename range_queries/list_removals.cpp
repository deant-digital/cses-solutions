#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct BIT {
  vector<ll> tree;
  ll n;
  BIT(ll n) : tree(n + 1), n(n) {
  }
  void point_update(ll i, ll x) {
    for (++i; i <= n; i += i & -i) tree[i] += x;
  }
  ll query(ll i) {
    ll s = 0;
    for (++i; i; i -= i & -i) s += tree[i];
    return s;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  BIT bit(n);
  for (ll i = 0; i < n; ++i) bit.point_update(i, 1);
  for (ll i = 0; i < n; ++i) {
    ll idx;
    cin >> idx;
    ll l = 0;
    ll r = n - 1;
    while (l < r) {
      ll m = l + ((r - l) >> 1);
      if (bit.query(m) < idx) l = m + 1;
      else r = m;
    }
    if (i) cout << ' ';
    cout << vec[l];
    bit.point_update(l, -1);
  }
  cout << '\n';
}
