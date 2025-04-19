#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, x;
  cin >> n >> x;
  vector<ll> vec(n);
  for (ll &v : vec) cin >> v;
  sort(vec.begin(), vec.end());
  ll ans = 0;
  ll l = 0, r = n - 1;
  while (l < r) {
    ++ans;
    if (vec[l] + vec[r] <= x) ++l;
    --r;
  }
  if (l == r) ++ans;
  cout << ans << '\n';
}
