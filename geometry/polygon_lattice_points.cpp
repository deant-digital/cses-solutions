#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<pair<ll, ll>> v(n + 1);
  for (ll i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
  v[n] = v[0];
  ll area2 = 0;
  ll b = 0;
  for (ll i = 0; i < n; ++i) {
    area2 += v[i].first * v[i + 1].second - v[i].second * v[i + 1].first;
    b += gcd(llabs(v[i].first - v[i + 1].first),
             llabs(v[i].second - v[i + 1].second));
  }
  area2 = llabs(area2);
  cout << ((area2 + 2 - b) >> 1) << ' ' << b << '\n';
}
