#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(ll x) {
  ll ans = 1;
  while (~x & 1) {
    x >>= 1;
    ++ans;
  }
  for (ll i = 3; i * i <= x; i += 2) {
    ll cnt = 1;
    while (x % i == 0) {
      x /= i;
      ++cnt;
    }
    ans *= cnt;
  }
  if (x > 2) ans <<= 1;
  return ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  while (n--) {
    ll x;
    cin >> x;
    cout << solve(x) << '\n';
  }
}
