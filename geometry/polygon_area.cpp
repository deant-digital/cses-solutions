#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<pair<ll, ll>> v(n);
  for (auto &[a, b] : v) cin >> a >> b;
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    ll j = i < n - 1 ? i + 1 : 0;
    ans += v[i].first * v[j].second - v[i].second * v[j].first;
  }
  cout << llabs(ans) << '\n';
}
