#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vector<ll> vec(k);
  for (ll &x : vec) cin >> x;
  ll ans = 0;
  for (ll i = 1; i < 1LL << k; ++i) {
    ll prod = 1;
    bool bl = false;
    for (ll j = k - 1; j >= 0; --j) {
      if (~i & 1LL << j) continue;
      if (prod > n / vec[j]) {
        bl = true;
        break;
      }
      prod *= vec[j];
    }
    if (bl) continue;
    ans += n / prod * ((__builtin_popcountll(i) & 1) ? 1 : -1);
  }
  cout << ans << '\n';
}
