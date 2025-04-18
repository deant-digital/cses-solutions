#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    cout << (i * i * (i * i - 1) >> 1) - 4 * (i - 1) * (i - 2) << '\n';
  }
}
