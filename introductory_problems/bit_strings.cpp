#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  ll ans = 1;
  while (n--) ans = (ans << 1) % MOD;
  cout << ans << '\n';
}
