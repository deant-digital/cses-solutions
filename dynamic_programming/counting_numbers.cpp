#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll a, b;
  cin >> a >> b;
  ll dp[20][2][2][11];
  auto solve_helper = [&](vector<ll>& digits, ll idx, bool tight,
                          bool leading_zeroes, ll last_digit,
                          auto&& self) -> ll {
    if (idx == digits.size()) return 1;
    if (dp[idx][tight][leading_zeroes][last_digit + 1] != -1) {
      return dp[idx][tight][leading_zeroes][last_digit + 1];
    }
    ll ans = 0;
    ll upper_bound = tight ? digits[idx] : 9;
    for (ll i = 0; i <= upper_bound; ++i) {
      if (!leading_zeroes && i == last_digit) continue;
      ans += self(digits, idx + 1, tight && i == upper_bound,
                  leading_zeroes && i == 0, leading_zeroes && i == 0 ? -1 : i,
                  self);
    }
    return dp[idx][tight][leading_zeroes][last_digit + 1] = ans;
  };
  auto solve = [&](ll n) -> ll {
    if (n < 0) return 0;
    if (n == 0) return 1;
    vector<ll> digits;
    while (n) {
      digits.push_back(n % 10);
      n /= 10;
    }
    reverse(digits.begin(), digits.end());
    memset(dp, -1, sizeof(dp));
    return solve_helper(digits, 0, true, true, -1, solve_helper);
  };
  cout << solve(b) - solve(a - 1) << '\n';
}
