#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  ll ans = 0;
  while (n >= 5) ans += (n /= 5);
  cout << ans << '\n';
}
