#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  ll ans = n;
  for (ll i = 1; i < n; ++i) {
    ll x;
    cin >> x;
    ans ^= i ^ x;
  }
  cout << ans << '\n';
}
