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
  ll q;
  cin >> q;
  const ll MOD = 1e9 + 7;
  while (q--) {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, pow(b, c, MOD - 1), MOD) << '\n';
  }
}
