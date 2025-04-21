#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> edges(n + 1);
  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({b, c});
  }
  using ll3 = array<ll, 3>;
  priority_queue<ll3, vector<ll3>, greater<ll3>> pq;
  pq.push({0, 1, 1});
  vector<vector<ll>> min_dists(n + 1, vector<ll>(2, LLONG_MAX));
  while (pq.size()) {
    auto [a, b, c] = pq.top();
    pq.pop();
    if (a >= min_dists[b][c]) continue;
    min_dists[b][c] = a;
    for (auto [x, y] : edges[b]) {
      pq.push({a + y, x, c});
      if (c) pq.push({a + (y >> 1), x, 0});
    }
  }
  cout << min(min_dists[n][0], min_dists[n][1]) << '\n';
}
