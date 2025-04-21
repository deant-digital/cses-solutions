#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> adjs(n + 1);
  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    adjs[a].push_back({b, c});
  }
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  vector<ll> shortest(n + 1, LLONG_MAX);
  pq.push({0, 1});
  while (pq.size()) {
    auto [len, x] = pq.top();
    pq.pop();
    if (len >= shortest[x]) continue;
    shortest[x] = len;
    for (auto [p, q] : adjs[x]) {
      pq.push({len + q, p});
    }
  }
  for (ll i = 1; i <= n; ++i) {
    if (i - 1) cout << ' ';
    cout << shortest[i];
  }
  cout << '\n';
}
