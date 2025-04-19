#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  sort(vec.begin(), vec.end());
  ll mid = vec[(vec.size() - 1) >> 1];
  ll ans = 0;
  for (ll i : vec) ans += llabs(i - mid);
  cout << ans << '\n';
}
