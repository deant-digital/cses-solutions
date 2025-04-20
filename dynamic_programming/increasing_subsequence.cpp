#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> vec;
  while (n--) {
    ll x;
    cin >> x;
    auto it = lower_bound(vec.begin(), vec.end(), x);
    if (it == vec.end()) vec.push_back(x);
    else *it = x;
  }
  cout << vec.size() << '\n';
}
