#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;
    cout << ((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a ? "YES\n" : "NO\n");
  }
}
