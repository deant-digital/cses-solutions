#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string str;
  cin >> str;
  sort(str.begin(), str.end());
  vector<string> ans;
  do {
    ans.push_back(str);
  } while (next_permutation(str.begin(), str.end()));
  cout << ans.size() << '\n';
  for (string &s : ans) cout << s << '\n';
}
