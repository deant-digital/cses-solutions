#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll cross(ll x, ll y, ll x1, ll y1, ll x2, ll y2) {
  return (x1 - x) * (y2 - y) - (x2 - x) * (y1 - y);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<pair<ll, ll>> points(n);
  for (auto &[x, y] : points) cin >> x >> y;
  sort(points.begin(), points.end());
  vector<pair<ll, ll>> hull;
  for (ll i = 0; i < 2; ++i) {
    ll start = hull.size();
    for (auto &p : points) {
      while (hull.size() >= start + 2) {
        auto &p1 = hull[hull.size() - 2];
        auto &p2 = hull[hull.size() - 1];
        if (cross(p.first, p.second, p1.first, p1.second, p2.first, p2.second) >
            0) {
          hull.pop_back();
        } else break;
      }
      hull.push_back(p);
    }
    hull.pop_back();
    reverse(points.begin(), points.end());
  }
  cout << hull.size() << '\n';
  for (auto &[x, y] : hull) cout << x << ' ' << y << '\n';
}
