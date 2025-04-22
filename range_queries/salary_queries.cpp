#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  ordered_set<pair<ll, ll>> oset;
  vector<ll> vec(n);
  for (ll i = 0; i < n; ++i) {
    cin >> vec[i];
    oset.insert({vec[i], i});
  }
  while (m--) {
    char c;
    ll a, b;
    cin >> c >> a >> b;
    if (c == '?') {
      ll x2 = oset.order_of_key({b + 1, 0});
      ll x1 = oset.order_of_key({a, 0});
      cout << x2 - x1 << '\n';
    } else {
      --a;
      oset.erase(oset.find({vec[a], a}));
      oset.insert({vec[a] = b, a});
    }
  }
}
