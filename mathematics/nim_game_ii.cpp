#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll ans = 0;
    while (n--) {
      ll x;
      cin >> x;
      ans ^= x % 4;
    }
    cout << (ans ? "first" : "second") << '\n';
  }
}
