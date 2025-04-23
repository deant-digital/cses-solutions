#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> vec(n), freq(1e6 + 1);
  for (ll &x : vec) {
    cin >> x;
    ++freq[x];
  }
  vector<ll> mu(1e6 + 1, 1), primes;
  vector<bool> is_composite(1e6 + 1);
  mu[0] = 0;
  for (ll i = 2; i <= 1e6; ++i) {
    if (!is_composite[i]) {
      primes.push_back(i);
      mu[i] = -1;
    }
    for (ll prime : primes) {
      ll multiple = i * prime;
      if (multiple > 1e6) break;
      is_composite[multiple] = true;
      if (i % prime == 0) mu[multiple] = 0;
      else mu[multiple] = -mu[i];
    }
  }
  vector<ll> counts(1e6 + 1);
  for (ll i = 1; i <= 1e6; ++i) {
    for (ll j = i; j <= 1e6; j += i) counts[i] += freq[j];
  }
  ll ans = 0;
  for (ll i = 1; i <= 1e6; ++i) {
    if (mu[i] == 0) continue;
    ans += mu[i] * counts[i] * (counts[i] - 1) >> 1;
  }
  cout << ans << '\n';
}
