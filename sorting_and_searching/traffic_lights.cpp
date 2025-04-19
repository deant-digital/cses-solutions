#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll x, n;
  cin >> x >> n;
  set<ll> st;
  st.insert(0);
  st.insert(x);
  multiset<ll> dists;
  dists.insert(x);
  for (ll i = 0; i < n; ++i) {
    ll v;
    cin >> v;
    ll l = *prev(st.lower_bound(v));
    ll r = *st.upper_bound(v);
    st.insert(v);
    dists.erase(dists.find(r - l));
    dists.insert(r - v);
    dists.insert(v - l);
    if (i) cout << ' ';
    cout << *dists.rbegin();
  }
  cout << '\n';
}
