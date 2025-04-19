#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  multiset<ll> h;
  while (n--) {
    ll x;
    cin >> x;
    h.insert(x);
  }
  while (m--) {
    ll t;
    cin >> t;
    auto it = h.upper_bound(t);
    if (it == h.begin()) {
      cout << "-1\n";
      continue;
    }
    it = prev(it);
    cout << *it << '\n';
    h.erase(it);
  }
}
