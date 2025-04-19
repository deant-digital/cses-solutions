#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, x;
  cin >> n >> x;
  vector<ll> vec(n);
  for (ll &v : vec) cin >> v;
  ll ans = 0;
  for (ll l = 0, r = 0, sum = 0; r < n; ++r) {
    sum += vec[r];
    while (sum > x && l < r) sum -= vec[l++];
    if (sum == x) ++ans;
  }
  cout << ans << '\n';
}
