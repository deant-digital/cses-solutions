#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  long double ans = 0;
  for (ll i = 1; i <= k; ++i) {
    ans += 1 - pow((i - 1) / (long double)k, n);
  }
  cout << fixed << setprecision(6) << ans << '\n';
}
