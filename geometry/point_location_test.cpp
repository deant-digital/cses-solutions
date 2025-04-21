#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;
  while (t--) {
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    ll cross = (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
    if (cross == 0) cout << "TOUCH\n";
    else if (cross > 0) cout << "LEFT\n";
    else cout << "RIGHT\n";
  }
}
