#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  long double ans = 0.0L;
  for (ll i = 0; i < n - 1; ++i) {
    for (ll j = i + 1; j < n; ++j) {
      ll a = vec[i], b = vec[j];
      if (a <= b) ans += (a - 1) / 2.0L / b;
      else ans += 1 - (b + 1) / 2.0L / a;
    }
  }
  cout << fixed << setprecision(6) << ans << '\n';
}
