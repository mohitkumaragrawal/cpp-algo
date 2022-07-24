#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<int> S(N + 1), C(N + 1);
  for (int i = 1; i <= N; ++i) cin >> S[i];
  for (int i = 1; i <= N; ++i) cin >> C[i];

  // state - (number of elements picked, index of last led picked);
  // number of elements picked = [0, 3];
  ll inf = 1e+17;

  vector<vector<ll>> dp(N, vector<ll>(4, inf));
  for (ll i = 0; i < N; ++i) {
    dp[i][1] = C[i + 1];
  }
  for (ll j = 2; j <= 3; ++j) {
    for (ll i = 0; i < N; ++i) {
      // find index k such that k < i, and S[k] < S[i]
      // and minimize dp[j-1][k];

      ll tmp = inf;
      for (ll k = 0; k < i; ++k) {
        if (S[k + 1] < S[i + 1]) {
          tmp = min(tmp, dp[k][j - 1]);
        }
      }
      if (tmp == inf) continue;

      dp[i][j] = tmp + C[i + 1];
    }
  }

  ll ans = inf;
  for (ll i = 0; i < N; ++i) {
    if (ans > dp[i][3]) {
      ans = dp[i][3];
    }
  }
  if (ans == inf) ans = -1;
  cout << ans << endl;
}