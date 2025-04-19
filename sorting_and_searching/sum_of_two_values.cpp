#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, x;
  cin >> n >> x;
  vector<ll> vec(n);
  map<ll, ll> mp;
  for (ll i = 0; i < n; ++i) {
    cin >> vec[i];
    auto it = mp.find(vec[i]);
    if (it != mp.end()) {
      cout << it->second + 1 << ' ' << i + 1 << '\n';
      return 0;
    }
    mp[x - vec[i]] = i;
  }
  cout << "IMPOSSIBLE\n";
}
