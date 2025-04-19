#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct BIT {
  vector<ll> tree;
  BIT(ll n) : tree(n + 1) {};
  void update(ll i, ll x) {
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
  ll n, k;
  cin >> n >> k;
  BIT bit(n);
  for (ll i = 0; i < n; ++i) bit.update(i, 1);
  ll idx = 0;
  ll sz = n;
  for (ll i = 0; i < n; ++i) {
    idx = (idx + k) % sz;
    ll l = 0;
    ll r = n - 1;
    while (l < r) {
      ll m = l + ((r - l) >> 1);
      if (bit.query(m) > idx) r = m;
      else l = m + 1;
    }
    bit.update(l, -1);
    --sz;
    if (i) cout << ' ';
    cout << l + 1;
  }
  cout << '\n';
}
