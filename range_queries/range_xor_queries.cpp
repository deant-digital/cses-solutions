#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<ll> prefix(n + 1);
  for (ll i = 1; i <= n; ++i) {
    cin >> prefix[i];
    prefix[i] ^= prefix[i - 1];
  }
  while (m--) {
    ll a, b;
    cin >> a >> b;
    cout << (prefix[b] ^ prefix[a - 1]) << '\n';
  }
}
