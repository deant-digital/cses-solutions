#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll cross(ll x, ll y, ll x1, ll y1, ll x2, ll y2) {
  return (x1 - x) * (y2 - y) - (x2 - x) * (y1 - y);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> points(n + 1);
  for (ll i = 0; i < n; ++i) {
    cin >> points[i].first >> points[i].second;
  }
  points[n] = points[0];
  while (m--) {
    ll a, b;
    cin >> a >> b;
    ll count = 0;
    bool bl = false;
    for (ll i = 0; i < n; ++i) {
      ll x1 = points[i].first, y1 = points[i].second;
      ll x2 = points[i + 1].first, y2 = points[i + 1].second;
      if (min(x1, x2) <= a && a <= max(x1, x2) && min(y1, y2) <= b &&
          b <= max(y1, y2) && cross(a, b, x1, y1, x2, y2) == 0) {
        cout << "BOUNDARY\n";
        bl = true;
        break;
      }
      if (y1 > y2) {
        swap(y1, y2);
        swap(x1, x2);
      }
      if (y1 <= b && b < y2 && cross(a, b, x1, y1, x2, y2) > 0) ++count;
    }
    if (bl) continue;
    cout << ((count & 1) ? "INSIDE\n" : "OUTSIDE\n");
  }
}
