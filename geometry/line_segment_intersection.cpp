#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll cross(ll x, ll y, ll x1, ll y1, ll x2, ll y2) {
  return (x1 - x) * (y2 - y) - (y1 - y) * (x2 - x);
}

ll sign(ll x) {
  if (x == 0) return 0;
  return x > 0 ? 1 : -1;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;
  while (t--) {
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    ll c1 = sign(cross(x3, y3, x1, y1, x2, y2)) *
            sign(cross(x4, y4, x1, y1, x2, y2));
    ll c2 = sign(cross(x1, y1, x3, y3, x4, y4)) *
            sign(cross(x2, y2, x3, y3, x4, y4));
    if (c1 == 0 && c2 == 0) {
      cout << (max(x1, x2) >= min(x3, x4) && max(x3, x4) >= min(x1, x2) &&
                       max(y1, y2) >= min(y3, y4) && max(y3, y4) >= min(y1, y2)
                   ? "YES\n"
                   : "NO\n");
      continue;
    }
    cout << (c1 <= 0 && c2 <= 0 ? "YES\n" : "NO\n");
  }
}
