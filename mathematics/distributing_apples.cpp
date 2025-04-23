#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

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
  vector<ll> facts(2e6 + 1), factinvs(2e6 + 1);
  facts[0] = 1;
  factinvs[0] = 1;
  for (ll i = 1; i <= 2e6; ++i) {
    facts[i] = (facts[i - 1] * i) % MOD;
    factinvs[i] = pow(facts[i], MOD - 2, MOD);
  }
  auto choose = [&](ll n, ll k) -> ll {
    return facts[n] * factinvs[n - k] % MOD * factinvs[k] % MOD;
  };
  ll n, k;
  cin >> n >> k;
  // k + n - 1 choose k
  cout << choose(n + k - 1, k) << '\n';
}
