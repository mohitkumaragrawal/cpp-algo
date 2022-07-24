#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e+9 + 7;

int main() {
  int n, k;
  cin >> n >> k;

  // state -> last number in the sequence, number of elements in the sequence;

  vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 0));
  for (int i = 1; i <= n; ++i) {
    dp[1][i] = 1;
  }

  // Accused of being slow !
  // for (int i = 2; i <= k; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     // find all the factors of j
  //     for (int x = 1; x <= j; ++x) {
  //       if (j % x == 0) {
  //         dp[i][j] += dp[i - 1][x];
  //       }
  //       if (dp[i][j] > 10 * MOD) {
  //         dp[i][j] %= MOD;
  //       }
  //     }
  //   }
  // }

  for (int i = 1; i < k; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = j; k <= n; k += j) {
        dp[i + 1][k] += dp[i][j];
        if (dp[i + 1][k] > (MOD << 10)) dp[i + 1][k] %= MOD;
      }
    }
  }

  ll ans = 0;
  for (int j = 1; j <= n; ++j) {
    ans += dp[k][j];
  }

  cout << ans % MOD << endl;
}