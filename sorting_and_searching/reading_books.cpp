#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  ll s = 0, mx = 0;
  while (n--) {
    ll x;
    cin >> x;
    s += x;
    if (x > mx) mx = x;
  }
  cout << max(s, mx << 1) << '\n';
}
