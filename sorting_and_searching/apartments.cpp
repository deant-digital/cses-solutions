#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n), b(m);
  for (ll &x : a) cin >> x;
  for (ll &x : b) cin >> x;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ll ans = 0;
  for (ll i = 0, j = 0; i < n && j < m;) {
    if (b[j] < a[i] - k) ++j;
    else if (b[j] > a[i] + k) ++i;
    else {
      ++i;
      ++j;
      ++ans;
    }
  }
  cout << ans << '\n';
}
