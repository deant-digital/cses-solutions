#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<pair<pair<ll, ll>, ll>> vec(n);
  for (ll i = 0; i < n; ++i) {
    cin >> vec[i].first.first >> vec[i].first.second;
    vec[i].second = i;
  }
  sort(vec.begin(), vec.end());
  set<pair<ll, ll>> st;
  ll rooms = 0;
  vector<ll> ans(n);
  for (ll i = 0; i < n; ++i) {
    auto [a, b] = vec[i];
    auto it = st.upper_bound({a.first, 0});
    if (it == st.begin()) {
      ans[b] = ++rooms;
      st.insert({a.second, rooms});
    } else {
      it = prev(it);
      ll room = it->second;
      st.erase(it);
      ans[b] = room;
      st.insert({a.second, room});
    }
  }
  cout << rooms << '\n';
  for (ll i = 0; i < n; ++i) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  cout << '\n';
}
