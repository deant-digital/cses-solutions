#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  ll s = n * (n + 1) >> 1;
  if (s & 1) {
    cout << "NO\n";
    return 0;
  }
  ll t = s >> 1;
  vector<ll> v1, v2;
  for (ll i = n; i; --i) {
    if (t >= i) {
      t -= i;
      v1.push_back(i);
    } else v2.push_back(i);
  }
  cout << "YES\n";
  cout << v1.size() << '\n';
  for (ll i = 0; i < v1.size(); ++i) {
    if (i) cout << ' ';
    cout << v1[i];
  }
  cout << '\n';
  cout << v2.size() << '\n';
  for (ll i = 0; i < v2.size(); ++i) {
    if (i) cout << ' ';
    cout << v2[i];
  }
  cout << '\n';
}
