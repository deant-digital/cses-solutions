#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<ll> v(n);
  for (ll &x : v) cin >> x;
  vector<ll> lg2(n + 1);
  for (ll i = 2; i <= n; ++i) lg2[i] = lg2[i >> 1] + 1;
  vector<vector<ll>> st(n, vector<ll>(lg2[n] + 1));
  for (ll i = 0; i < n; ++i) st[i][0] = v[i];
  for (ll i = 1; i <= lg2.back(); ++i) {
    for (ll j = 0; j + (1 << i) - 1 < n; ++j) {
      st[j][i] = min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    }
  }
  while (m--) {
    ll a, b;
    cin >> a >> b;
    --a, --b;
    ll i = lg2[b - a + 1];
    cout << min(st[a][i], st[b + 1 - (1 << i)][i]) << '\n';
  }
}
