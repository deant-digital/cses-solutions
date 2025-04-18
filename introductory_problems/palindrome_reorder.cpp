#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string str;
  cin >> str;
  ll cnt[26] = {};
  ll odds = 0;
  for (char c : str)
    if (++cnt[c - 'A'] & 1) ++odds;
    else --odds;
  if (odds >> 1) cout << "NO SOLUTION\n";
  else {
    string s, m;
    for (ll i = 0; i < 26; ++i) {
      s += string(cnt[i] >> 1, i + 'A');
      if (cnt[i] & 1) m = string(1, i + 'A');
    }
    string t = s;
    reverse(t.begin(), t.end());
    cout << s << m << t << '\n';
  }
}
