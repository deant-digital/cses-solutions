#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll exp(ll n) {
  ll i = 1;
  ll j = 10;
  while (n) {
    if (n & 1) i *= j;
    j *= j;
    n >>= 1;
  }
  return i;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll q;
  cin >> q;
  while (q--) {
    ll k;
    cin >> k;
    --k;
    ll digits = 1;
    ll offset;
    while (k >= (offset = 9 * digits * exp(digits - 1))) {
      k -= offset;
      ++digits;
    }
    cout << to_string(exp(digits - 1) + k / digits)[k % digits] << '\n';
  }
}
