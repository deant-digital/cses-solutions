#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  set<ll> st;
  while (n--) {
    ll x;
    cin >> x;
    st.insert(x);
  }
  cout << st.size() << '\n';
}
