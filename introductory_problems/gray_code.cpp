#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  for (ll i = 0; i < 1LL << n; ++i) {
    cout << bitset<16>(i ^ i >> 1).to_string().substr(16 - n) << '\n';
  }
}
