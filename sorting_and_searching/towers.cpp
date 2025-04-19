#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  multiset<ll> st;
  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    auto it = st.upper_bound(x);
    if (it != st.end()) st.erase(it);
    st.insert(x);
  }
  cout << st.size() << '\n';
}
