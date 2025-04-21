#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<ll, ll>>> edges(n + 1);
  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({b, c});
  }
  using node = pair<ll, ll>;
  priority_queue<node, vector<node>, greater<node>> pq;
  pq.push({0, 1});
  vector<ll> prices;
  prices.reserve(k);
  vector<ll> cnts(n + 1);
  while (pq.size()) {
    auto [price, idx] = pq.top();
    pq.pop();
    if (++cnts[idx] > k) continue;
    if (idx == n) {
      prices.push_back(price);
      if (prices.size() == k) break;
    }
    for (auto [i, p] : edges[idx]) {
      pq.push({price + p, i});
    }
  }
  for (ll i = 0; i < k; ++i) {
    if (i) cout << ' ';
    cout << prices[i];
  }
  cout << '\n';
}
