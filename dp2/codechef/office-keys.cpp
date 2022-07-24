#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
  int N, kn, p0;
  cin >> N >> kn >> p0;

  vector<int> p(N), k(kn);
  for (int &i : p)
    cin >> i;
  for (int &i : k)
    cin >> i;

  sort(p.begin(), p.end());
  sort(k.begin(), k.end());

  int inf = 1e+17;
  vector<vector<int>> dp(N + 1, vector<int>(kn + 1, inf));
  dp[0][0] = 0;

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < kn; ++j)
    {
      // don't take jth key;
      dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);

      // take that key
      int cost = abs(p[i] - k[j]) + abs(k[j] - p0);
      dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], cost));
    }
  }
  int ans = *min_element(dp[N].begin(), dp[N].end());
  cout << ans << endl;

  // for (int j = 0; j < kn; ++j) {
  //   dp[0][j] = abs(p[0] - k[j]) + abs(k[j] - p0);
  // }

  // for (int i = 0; i < N-1; ++i) {
  //   for (int j = 0; j < kn - 1; ++j) {
  //     if (dp[i][j] == -1) continue;

  //     int cost = abs(p[i+1] - k[j]) + abs(k[j] - p0);
  //     int possibleValue = max(dp[i][j], cost);
  //     if (dp[i+1][j+1] == -1) {
  //       dp[i+1][j+1] = possibleValue;
  //     } else {
  //       dp[i+1][j+1] = min(dp[i+1][j+1], possibleValue);
  //     }

  //     if (dp[i][j+1] == -1) {
  //       dp[i][j+1] = dp[i][j];
  //     } else {
  //       dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
  //     }
  //   }
  // }

  // int ans = -1;
  // for (int j = 0; j < kn; ++j) {
  //   if (dp[N-1][j] == -1) continue;

  //   if (ans == -1) {
  //     ans = dp[N-1][j];
  //   } else {
  //     ans = min(ans, dp[N-1][j]);
  //   }
  // }
  // cout << ans << endl;
}