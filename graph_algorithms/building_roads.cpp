#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct DSU {
  map<ll, ll> mp;
  ll find(ll n) {
    auto it = mp.find(n);
    if (it == mp.end()) return mp[n] = n;
    return it->second == n ? n : it->second = find(it->second);
  }
  void unite(ll a, ll b) {
    mp[find(a)] = find(b);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  DSU dsu;
  while (m--) {
    ll a, b;
    cin >> a >> b;
    dsu.unite(a, b);
  }
  set<ll> parents;
  for (ll i = 1; i <= n; ++i) parents.insert(dsu.find(i));
  vector<ll> vec(parents.begin(), parents.end());
  cout << vec.size() - 1 << '\n';
  for (ll i = 1; i < vec.size(); ++i) {
    cout << vec[i - 1] << ' ' << vec[i] << '\n';
  }
}
