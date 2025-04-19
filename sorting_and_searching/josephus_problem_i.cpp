#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(ll n, ll k) {
  if (n == 1) return 1;
  if (k << 1 <= n) return k << 1;
  if (n & 1) {
    ll v = solve(n - (n >> 1), k - (n >> 1));
    return v == 1 ? n : v * 2 - 3;
  }
  return solve(n >> 1, k - (n >> 1)) * 2 - 1;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    if (i ^ 1) cout << ' ';
    cout << solve(n, i);
  }
  cout << '\n';
}
