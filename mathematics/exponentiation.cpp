#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll solve(ll a, ll b) {
  a %= MOD;
  b %= MOD - 1;
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll q;
  cin >> q;
  while (q--) {
    ll a, b;
    cin >> a >> b;
    cout << solve(a, b) << '\n';
  }
}
