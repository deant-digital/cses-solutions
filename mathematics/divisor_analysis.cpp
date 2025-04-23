#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll pow(ll a, ll b, ll mod) {
  a %= mod;
  b %= mod - 1;
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<pair<ll, ll>> vec(n);
  for (auto &[a, b] : vec) cin >> a >> b;
  ll num = 1;
  ll sum = 1;
  ll prod = 1;
  const ll MOD = 1e9 + 7;
  ll num2 = 1;
  for (ll i = 0; i < n; ++i) {
    auto [x, k] = vec[i];
    num = (num * (k + 1)) % MOD;
    sum = sum * (pow(x, k + 1, MOD) - 1) % MOD * pow(x - 1, MOD - 2, MOD) % MOD;
    prod = pow(prod, k + 1, MOD) *
           pow(x, (k * (k + 1) >> 1) % (MOD - 1) * num2 % (MOD - 1), MOD) % MOD;
    num2 = (num2 * (k + 1)) % (MOD - 1);
  }
  cout << num << ' ' << sum << ' ' << prod << '\n';
}
