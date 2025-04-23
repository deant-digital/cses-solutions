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
    bool all_even = true;
    while (n--) {
      ll x;
      cin >> x;
      if (x % 2) all_even = false;
    }
    cout << (all_even ? "second" : "first") << '\n';
  }
}
