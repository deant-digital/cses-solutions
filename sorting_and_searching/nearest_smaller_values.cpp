#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (ll &x : vec) cin >> x;
  stack<ll> stk;
  for (ll i = 0; i < n; ++i) {
    while (stk.size() && vec[stk.top()] >= vec[i]) stk.pop();
    if (i) cout << ' ';
    if (stk.size()) cout << stk.top() + 1;
    else cout << 0;
    stk.push(i);
  }
  cout << '\n';
}
