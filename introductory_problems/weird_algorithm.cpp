#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  cout << n;
  while (n ^ 1) {
    if (n & 1) n = n * 3 + 1;
    else n >>= 1;
    cout << ' ' << n;
  }
  cout << '\n';
}
