#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct BIT {
  vector<ll> tree;
  ll n;
  BIT(ll n) : tree(n + 1), n(n) {
  }
  void update(ll i, ll x) {
    for (++i; i <= n; i += i & -i) tree[i] += x;
  }
  ll query(ll i) {
    ll s = 0;
    for (++i; i; i -= i & -i) s += tree[i];
    return s;
  }
  ll query(ll l, ll r) {
    return query(r) - query(l - 1);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q;
  cin >> n >> q;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  vector<array<ll, 3>> queries(q);
  for (ll i = 0; i < q; ++i) {
    cin >> queries[i][1] >> queries[i][0];
    queries[i][2] = i;
  }
  sort(queries.begin(), queries.end());
  vector<ll> ans(q);
  map<ll, ll> mp;
  BIT bit(n);
  ll q_idx = 0;
  for (ll i = 0; i < n; ++i) {
    auto it = mp.find(vec[i]);
    if (it != mp.end()) {
      bit.update(it->second, -1);
      it->second = i;
    } else {
      mp[vec[i]] = i;
    }
    bit.update(i, 1);
    while (q_idx < q && queries[q_idx][0] - 1 == i) {
      ans[queries[q_idx][2]] = bit.query(i) - bit.query(queries[q_idx][1] - 2);
      ++q_idx;
    }
  }
  for (ll &v : ans) cout << v << '\n';
}
