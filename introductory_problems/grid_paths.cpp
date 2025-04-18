#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string str;
  cin >> str;
  ll ans = 0;
  bool vis[9][9] = {};
  ll a[48] = {};
  for (ll i = 0; i < 48; ++i) {
    if (str[i] == 'R') a[i] = 0;
    else if (str[i] == 'D') a[i] = 1;
    else if (str[i] == 'L') a[i] = 2;
    else if (str[i] == 'U') a[i] = 3;
    else a[i] = 5;
  }
  for (ll i = 0; i < 9; ++i)
    vis[i][0] = vis[i][8] = vis[0][i] = vis[8][i] = true;
  ll dirs[5] = {0, 1, 0, -1, 0};
  function<void(ll, ll, ll)> dfs = [&](ll i, ll x, ll y) {
    if (x == 7 && y == 1) {
      if (i == 48) ++ans;
      return;
    }
    if (vis[x - 1][y] && vis[x + 1][y] && !vis[x][y - 1] && !vis[x][y + 1])
      return;
    if (!vis[x - 1][y] && !vis[x + 1][y] && vis[x][y - 1] && vis[x][y + 1])
      return;
    if (i == 48) return;
    if (48 - i < abs(x - 7) + abs(y - 1)) return;
    if (a[i] < 4) {
      ll p = x + dirs[a[i]];
      ll q = y + dirs[a[i] + 1];
      if (vis[p][q]) return;
      vis[p][q] = true;
      dfs(i + 1, p, q);
      vis[p][q] = false;
    } else {
      for (ll j = 0; j < 4; ++j) {
        ll p = x + dirs[j];
        ll q = y + dirs[j + 1];
        if (vis[p][q]) continue;
        vis[p][q] = true;
        dfs(i + 1, p, q);
        vis[p][q] = false;
      }
    }
  };
  vis[1][1] = true;
  dfs(0, 1, 1);
  cout << ans << '\n';
}
