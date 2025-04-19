#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> vec(n);
  for (auto &[a, b] : vec) cin >> b >> a;
  sort(vec.begin(), vec.end());
  multiset<ll> mst;
  ll ans = 0;
  for (auto [a, b] : vec) {
    auto it = mst.upper_bound(b);
    if (it == mst.begin()) {
      if (mst.size() < k) {
        mst.insert(a);
        ++ans;
      }
    } else {
      mst.erase(prev(it));
      mst.insert(a);
      ++ans;
    }
  }
  cout << ans << '\n';
}
