#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  map<ll, ll> mp;
  ll ans = 0;
  for (ll l = 0, r = 0; r < n; ++r) {
    ++mp[vec[r]];
    while (mp.size() > k) {
      if (--mp[vec[l]] == 0) mp.erase(vec[l]);
      ++l;
    }
    ans += r - l + 1;
  }
  cout << ans << '\n';
}
