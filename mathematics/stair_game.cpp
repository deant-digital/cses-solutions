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
    vector<ll> vec(n);
    for (ll &x : vec) cin >> x;
    ll ans = 0;
    for (ll i = 2; i <= n; i += 2) {
      ans ^= vec[i - 1];
    }
    cout << (ans ? "first" : "second") << '\n';
  }
}
