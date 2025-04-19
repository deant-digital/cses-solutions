#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, x;
  cin >> n >> x;
  vector<pair<ll, ll>> vec(n);
  for (ll i = 0; i < n; ++i) {
    cin >> vec[i].first;
    vec[i].second = i;
  }
  sort(vec.begin(), vec.end());
  for (ll i = 0; i < n - 3; ++i) {
    for (ll j = i + 1; j < n - 2; ++j) {
      ll l = j + 1;
      ll r = n - 1;
      while (l < r) {
        ll s = vec[i].first + vec[j].first + vec[l].first + vec[r].first;
        if (s == x) {
          cout << vec[i].second + 1 << ' ' << vec[j].second + 1 << ' '
               << vec[l].second + 1 << ' ' << vec[r].second + 1;
          return 0;
        } else if (s < x) ++l;
        else --r;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}
