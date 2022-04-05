#include <iostream>
#include <vector>
using namespace std;

using i64 = int64_t;

i64 countWays(int sum, vector<int>& coins) {
  int m = coins.size();
  vector<vector<i64>> dp(m+1, vector<i64>(sum+1));

  for (int i = 0; i <= m; ++i) {
    dp[i][0] = 1;
  }
  for (int j = 1; j <= sum; ++j) {
    dp[0][j] = 0;
  }

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= sum; ++j) {
      if (j >= coins[i-1]) {
        dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  return dp[m][sum];
}

int main() {
  int sum, n;
  cin >> sum >> n;
  vector<int> coins(n);
  for (int& i: coins) {
    cin >> i;
  }

  cout << countWays(sum, coins) << endl;
}