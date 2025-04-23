#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(ll n, ll k) {
  if (n == 1) return 1;
  if (k << 1 <= n) return k << 1;
  ll res = solve(n - (n >> 1), k - (n >> 1));
  if (n & 1) {
    if (res == 1) return n;
    return 2 * res - 3;
  }
  return res * 2 - 1;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll q;
  cin >> q;
  while (q--) {
    ll n, k;
    cin >> n >> k;
    cout << solve(n, k) << '\n';
  }
}
