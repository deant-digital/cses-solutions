#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  vector<ll> prefix(n + 1);
  for (ll i = 1; i <= n; ++i) prefix[i] = prefix[i - 1] + vec[i - 1];
  multiset<ll> sums;
  for (ll i = a; i <= b; ++i) sums.insert(prefix[i]);
  ll ans = *sums.rbegin();
  for (ll i = 1; i + a <= n; ++i) {
    sums.erase(sums.find(prefix[i + a - 1]));
    sums.insert(prefix[min(i + b, n)]);
    ll val = *sums.rbegin() - prefix[i];
    if (val > ans) ans = val;
  }
  cout << ans << '\n';
}
