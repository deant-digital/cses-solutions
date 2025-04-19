#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<ll> vec(n + 1), pos(n + 2);
  for (ll i = 1; i <= n; ++i) {
    cin >> vec[i];
    pos[vec[i]] = i;
  }
  pos[n + 1] = n + 1;
  ll ans = 1;
  for (ll i = 2; i <= n; ++i) {
    if (pos[i - 1] > pos[i]) ++ans;
  }
  while (m--) {
    ll a, b;
    cin >> a >> b;
    if (a < pos[vec[a] - 1] && b >= pos[vec[a] - 1]) --ans;
    if (a > pos[vec[a] + 1] && b <= pos[vec[a] + 1]) --ans;
    if (a >= pos[vec[a] - 1] && b < pos[vec[a] - 1]) ++ans;
    if (a <= pos[vec[a] + 1] && b > pos[vec[a] + 1]) ++ans;
    pos[vec[a]] = b;
    if (b < pos[vec[b] - 1] && a >= pos[vec[b] - 1]) --ans;
    if (b > pos[vec[b] + 1] && a <= pos[vec[b] + 1]) --ans;
    if (b >= pos[vec[b] - 1] && a < pos[vec[b] - 1]) ++ans;
    if (b <= pos[vec[b] + 1] && a > pos[vec[b] + 1]) ++ans;
    pos[vec[b]] = a;
    swap(vec[a], vec[b]);
    cout << ans << '\n';
  }
}
