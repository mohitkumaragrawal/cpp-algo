#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> wt(N), val(N);
  for (int& x : wt) cin >> x;
  for (int& x : val) cin >> x;

  int W;
  cin >> W;

  vector<vector<int>> dp(N, vector<int>(W + 1, -1));

  dp[0][0] = 0;
  dp[0][wt[0]] = val[0];

  for (int i = 1; i < N; ++i) {
    dp[i][0] = 0;

    for (int j = 1; j <= W; ++j) {
      dp[i][j] = dp[i - 1][j];

      if (j >= wt[i]) {
        dp[i][j] = max(dp[i][j], val[i] + dp[i - 1][j - wt[i]]);
      }
    }
  }

  cout << dp[N - 1][W] << endl;
}