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
  vector<ll> vec(n);
  map<ll, ll> compress, decompress;
  for (ll &x : vec) {
    cin >> x;
    compress[x] = 0;
  }
  ll idx = 0;
  for (auto &[a, b] : compress) {
    b = idx++;
    decompress[b] = a;
  }
  BIT bit(idx);
  for (ll i = 0; i < n; ++i) {
    bit.update(compress[vec[i]], 1);
    if (i >= k - 1) {
      ll len = (k + 1) >> 1;
      ll l = 0;
      ll r = idx - 1;
      while (l < r) {
        ll m = l + ((r - l) >> 1);
        if (bit.query(m) >= len) r = m;
        else l = m + 1;
      }
      if (i - k + 1) cout << ' ';
      cout << decompress[l];
      bit.update(compress[vec[i - k + 1]], -1);
    }
  }
  cout << '\n';
}
