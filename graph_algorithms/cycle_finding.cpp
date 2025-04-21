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
  vector<ll> parents(n + 1);
  vector<ll> min_dists(n + 1);
  ll last = -1;
  for (ll i = 0; i < n && last; ++i) {
    last = 0;
    for (ll j = 1; j <= n; ++j) {
      for (auto [x, y] : edges[j]) {
        if (min_dists[j] + y < min_dists[x]) {
          min_dists[x] = min_dists[j] + y;
          parents[x] = j;
          last = x;
        }
      }
    }
  }
  if (last == 0) {
    cout << "NO\n";
    return 0;
  }
  ll cur = last;
  for (ll i = 1; i < n; ++i) cur = parents[cur];
  last = cur;
  vector<ll> ans;
  do {
    ans.push_back(cur);
    cur = parents[cur];
  } while (cur != last);
  ans.push_back(cur);
  cout << "YES\n";
  for (ll i = ans.size() - 1; i >= 0; --i) {
    cout << ans[i];
    if (i) cout << ' ';
  }
  cout << '\n';
}
