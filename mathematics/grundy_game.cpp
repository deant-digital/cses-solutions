#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<ll> g(2001);
  for (ll n = 3; n < 2001; ++n) {
    vector<bool> seen(2001);
    for (ll i = 1; i < n - i; ++i) {
      ll x = g[i] ^ g[n - i];
      if (x < 2001) seen[x] = true;
    }
    ll mex = 0;
    while (seen[mex]) ++mex;
    g[n] = mex;
  }
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    cout << (n >= 2001 || g[n] > 0 ? "first" : "second") << '\n';
  }
}
