#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<string> grid(8);
  for (auto &row : grid) cin >> row;
  ll ans = 0;
  bitset<8> cols;
  bitset<15> diags1, diags2;
  function<void(ll)> backtrack = [&](ll i) {
    if (i == 8) {
      ++ans;
      return;
    }
    for (ll j = 0LL; j < 8LL; ++j) {
      if (grid[i][j] == '*' || cols[j] || diags1[i + j] || diags2[i + (7 - j)]) continue;
      cols[j] = diags1[i + j] = diags2[i + (7 - j)] = true;
      backtrack(i + 1);
      cols[j] = diags1[i + j] = diags2[i + (7 - j)] = false;
    }
  };
  backtrack(0);
  cout << ans << '\n';
}
