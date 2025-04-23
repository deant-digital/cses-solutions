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
  vector<ll> facts(1e6 + 1), factinvs(1e6 + 1);
  facts[0] = 1;
  factinvs[0] = 1;
  for (ll i = 1; i <= 1e6; ++i) {
    facts[i] = (facts[i - 1] * i) % MOD;
    factinvs[i] = pow(facts[i], MOD - 2, MOD);
  }
  ll n;
  cin >> n;
  if (n & 1) {
    cout << "0\n";
    return 0;
  }
  ll a = 0, b = 0;
  string str;
  cin >> str;
  for (char c : str) {
    if (c == '(') ++a;
    else ++b;
    if (a < b) {
      cout << "0\n";
      return 0;
    }
  }
  if (a > n >> 1) {
    cout << "0\n";
    return 0;
  }
  auto choose = [&](ll n, ll k) -> ll {
    if (k < 0) return 0;
    return facts[n] * factinvs[k] % MOD * factinvs[n - k] % MOD;
  };
  cout << ((choose(n - a - b, (n >> 1) - a) -
            choose(n - a - b, (n >> 1) - a - 1)) %
               MOD +
           MOD) %
              MOD
       << '\n';
}
