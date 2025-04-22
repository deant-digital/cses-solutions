#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct BIT {
  vector<ll> tree;
  BIT(ll n) : tree(n + 1) {
  }
  void point_update(ll i, ll x) {
    for (++i; i < tree.size(); i += i & -i) tree[i] += x;
  }
  ll query(ll i) {
    ll s = 0;
    for (++i; i; i -= i & -i) s += tree[i];
    return s;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<ll> vec(n + 1);
  for (ll i = 1; i <= n; ++i) cin >> vec[i];
  BIT bit1(n + 2);
  while (m--) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll a, b, u;
      cin >> a >> b >> u;
      bit1.point_update(a, u);
      bit1.point_update(b + 1, -u);
    } else {
      ll k;
      cin >> k;
      cout << vec[k] + bit1.query(k) << '\n';
    }
  }
}
