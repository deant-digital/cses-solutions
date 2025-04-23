#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> vec(1e6 + 1);
  while (n--) {
    ll x;
    cin >> x;
    ++vec[x];
  }
  for (ll i = 1e6; i >= 1; --i) {
    ll cnt = 0;
    for (ll j = i; j <= 1e6; j += i) cnt += vec[j];
    if (cnt >= 2) {
      cout << i << '\n';
      return 0;
    }
  }
}
