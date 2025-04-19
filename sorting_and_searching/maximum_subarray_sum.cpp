#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  ll cur = vec[0], mx = vec[0];
  for (ll i = 1; i < n; ++i) {
    if (cur < 0) cur = 0;
    if ((cur += vec[i]) > mx) mx = cur;
  }
  cout << mx << '\n';
}
