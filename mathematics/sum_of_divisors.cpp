#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  ll ans = n;
  const ll MOD = 1e9 + 7;
  for (ll i = 1; i < n; i = n / (n / (i + 1))) {
    ll a = n / i;
    ll b = n / (i + 1) + 1;
    ll len = (a - b + 1) % MOD;
    ans = (ans +
           i % MOD * len % MOD * ((a + b) % MOD) % MOD * ((ll)5e8 + 4) % MOD) %
          MOD;
  }
  cout << ans << '\n';
}
