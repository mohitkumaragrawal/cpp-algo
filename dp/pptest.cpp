#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

vector<bool> pp(true, 1000);
array<int, 101> reward;
array<int, 101> cost;
array<array<int, 101>, 101> dp;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, W;
    cin >> N >> W;

    for (int i = 1; i <= N; ++i) {
      int x, y, z;
      cin >> x >> y >> z;

      reward[i] = x * y;
      cost[i] = z;
    }

    for (int i = 0; i < dp.size(); ++i) dp[i][0] = 0;
    for (int j = 0; j < dp[0].size(); ++j) dp[0][j] = 0;

    for (int i = 1; i <= N; ++i) {
      for (int time = 1; time <= W; ++time) {
        if (cost[i] > time) {
          dp[i][time] = dp[i - 1][time];
        } else {
          dp[i][time] =
              max({reward[i] + dp[i - 1][time - cost[i]], dp[i - 1][time]});
        }
      }
    }

    cout << dp[N][W] << endl;
  }
}