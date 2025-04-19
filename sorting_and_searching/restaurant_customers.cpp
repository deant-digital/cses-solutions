#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<pair<ll, bool>> v(n << 1);
  while (n--) {
    ll l, r;
    cin >> l >> r;
    v[n << 1].first = l;
    v[n << 1 | 1].first = r;
    v[n << 1 | 1].second = true;
  }
  sort(v.begin(), v.end());
  ll mx = 0, cur = 0;
  for (auto &[a, b] : v) {
    if (b) --cur;
    else if (++cur > mx) mx = cur;
  }
  cout << mx << '\n';
}
