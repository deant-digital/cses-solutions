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
  void clear() {
    fill(tree.begin(), tree.end(), 0);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<pair<pair<ll, ll>, ll>> vec(n);
  map<ll, ll> compress;
  for (ll i = 0; i < n; ++i) {
    cin >> vec[i].first.first >> vec[i].first.second;
    vec[i].second = i;
    compress[vec[i].first.first] = 0;
    compress[vec[i].first.second] = 0;
  }
  ll idx = 0;
  for (auto &[a, b] : compress) b = idx++;
  sort(vec.begin(), vec.end(), [](auto &v1, auto &v2) {
    if (v1.first.first == v2.first.first) {
      return v1.first.second > v2.first.second;
    }
    return v1.first.first < v2.first.first;
  });
  BIT bit(idx);
  vector<ll> ans1(n), ans2(n);
  for (ll i = n - 1; i >= 0; --i) {
    ll compressed = compress[vec[i].first.second];
    ans1[vec[i].second] = bit.query(compressed);
    bit.update(compressed, 1);
  }
  bit.clear();
  for (ll i = 0; i < n; ++i) {
    ll compressed = compress[vec[i].first.second];
    ans2[vec[i].second] = i - bit.query(compressed - 1);
    bit.update(compressed, 1);
  }
  for (ll i = 0; i < n; ++i) {
    if (i) cout << ' ';
    cout << ans1[i];
  }
  cout << '\n';
  for (ll i = 0; i < n; ++i) {
    if (i) cout << ' ';
    cout << ans2[i];
  }
  cout << '\n';
}
