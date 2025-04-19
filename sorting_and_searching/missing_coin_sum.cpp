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
  ll ans = 1;
  for (ll &x : vec) {
    if (x > ans) break;
    else ans += x;
  }
  cout << ans << '\n';
}
