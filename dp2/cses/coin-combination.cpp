#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e+9 + 7;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll N, X;
  cin >> N >> X;

  vector<ll> coins(N);
  for (auto& i : coins) cin >> i;

  vector<ll> dp(X + 1, 0);
  dp[0] = 1;

  for (ll i = 0; i < X; ++i) {
    for (ll coin : coins) {
      if (i + coin > X) continue;
      dp[i + coin] = (dp[i + coin] + dp[i]) % MOD;
    }
  }

  cout << dp[X] << endl;
}