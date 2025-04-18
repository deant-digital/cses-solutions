#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<pair<ll, ll>> ans;
  function<void(ll, ll, ll, ll)> f = [&](ll n, ll a, ll b, ll c) {
    if (n == 1) {
      ans.push_back({a, b});
      return;
    }
    f(n - 1, a, c, b);
    ans.push_back({a, b});
    f(n - 1, c, b, a);
  };
  f(n, 1, 3, 2);
  cout << ans.size() << '\n';
  for (auto &[a, b] : ans) cout << a << ' ' << b << '\n';
}
