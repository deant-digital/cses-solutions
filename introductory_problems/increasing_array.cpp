#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  ll ans = 0;
  for (ll i = 1; i < n; ++i) {
    if (vec[i - 1] > vec[i]) {
      ans += vec[i - 1] - vec[i];
      vec[i] = vec[i - 1];
    }
  }
  cout << ans << '\n';
}
