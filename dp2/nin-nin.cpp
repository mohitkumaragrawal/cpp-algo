#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Now using constant space;
int ninjaTraining(int N, vector<vector<int>> &POINTS) {
  vector<int> dp(3);
  for (int j = 0; j < 3; ++j)
    dp[j] = POINTS[0][j];

  for (int i = 1; i < N; ++i) {
    vector<int> ndp(3);
    for (int j = 0; j < 3; ++j) {
      int M = -1;
      for (int k = 0; k < 3; ++k) {
        if (k == j)
          continue;
        M = max(M, dp[k]);
      }
      ndp[j] = POINTS[i][j] + M;
    }

    for (int j = 0; j < 3; ++j)
      dp[j] = ndp[j];
  }

  int ans = max({dp[0], dp[1], dp[2]});
  return ans;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    vector<vector<int>> POINTS(N, vector<int>(3));
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < 3; ++j)
        cin >> POINTS[i][j];

    cout << ninjaTraining(N, POINTS) << endl;
  }
}
