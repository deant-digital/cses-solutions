#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll pow(ll a, ll b, ll m) {
  a %= m;
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  cout << (pow(2, n * n, MOD) + 2 * pow(2, (n * n + 3) >> 2, MOD) +
           pow(2, (n * n + 1) >> 1, MOD)) *
              pow(4, MOD - 2, MOD) % MOD;
}
