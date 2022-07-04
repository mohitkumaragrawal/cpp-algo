#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  cout << "using dp" << endl;
  while (T--) {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      dp[i][0] = 1;
      dp[0][i] = 1;
    }

    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    cout << dp[m - 1][n - 1] << endl;
  }
}
