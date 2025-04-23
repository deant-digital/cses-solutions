#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vector<ll> moves(k);
  for (ll &x : moves) cin >> x;
  vector<bool> states(n + 1);
  sort(moves.begin(), moves.end());
  string ans;
  for (ll i = 1; i <= n; ++i) {
    bool bl = false;
    for (ll move : moves) {
      if (i - move < 0) break;
      if (!states[i - move]) {
        bl = true;
        break;
      }
    }
    if (!bl) {
      ans += 'L';
      continue;
    }
    states[i] = true;
    ans += 'W';
  }
  cout << ans << '\n';
}
