#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string str;
  cin >> str;
  ll cur = 1, mx = 1;
  for (ll i = 1; i < str.size(); ++i) {
    if (str[i] == str[i - 1]) {
      if (++cur > mx) mx = cur;
    } else cur = 1;
  }
  cout << mx << '\n';
}
