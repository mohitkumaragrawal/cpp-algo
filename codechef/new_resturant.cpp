#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e+9 + 7;

int main() {
  int T;
  cin >> T;

  while (T--) {
    ll N, M, K;
    cin >> N >> M >> K;

    vector<vector<ll>> dp(N+1, vector<ll>(K+2, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= K; ++j) {
        if (dp[i][j] == 0) continue;

        dp[i+1][j] = (dp[i+1][j] + j * dp[i][j]) % MOD;
        dp[i+1][j+1] = (dp[i+1][j+1] + (M-j) * dp[i][j]) % MOD;
        
      }
    }

    ll ans = 0;
    for (int j = 0; j <= K; ++j) {
      ans += dp[N][j];
    }
    ans %= MOD;
    cout << ans << endl;
  }
}
