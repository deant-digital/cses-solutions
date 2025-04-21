#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<pair<ll, ll>> vec(n);
  for (auto &[x, y] : vec) cin >> x >> y;
  sort(vec.begin(), vec.end());
  auto cmp = [&](auto &p1, auto &p2) {
    return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second;
  };
  auto dist = [](auto &p1, auto &p2) {
    ll dx = p1.first - p2.first;
    ll dy = p1.second - p2.second;
    return dx * dx + dy * dy;
  };
  auto sqrt = [](ll n) {
    ll l = 0;
    ll r = n;
    while (l < r) {
      ll m = l + ((r - l) >> 1);
      if (m * m >= n) r = m;
      else l = m + 1;
    }
    return l;
  };
  set<pair<ll, ll>, decltype(cmp)> points(cmp);
  points.insert(vec[0]);
  ll l = 0;
  ll ans = LLONG_MAX;
  for (ll i = 1; i < n; ++i) {
    while (l < i) {
      ll dx = vec[i].first - vec[l].first;
      if (dx * dx >= ans) points.erase(vec[l++]);
      else break;
    }
    set<pair<ll, ll>>::iterator lower, upper;
    if (ans == LLONG_MAX) {
      lower = points.begin();
      upper = points.end();
    } else {
      ll d = sqrt(ans);
      lower = points.lower_bound({0, vec[i].second - d});
      upper = points.upper_bound({0, vec[i].second + d});
    }
    for (auto it = lower; it != upper; ++it) {
      ll val = dist(*it, vec[i]);
      if (val < ans) ans = val;
    }
    points.insert(vec[i]);
  }
  cout << ans << '\n';
}
