#include <bits/stdc++.h>
using namespace std;

struct pos {
  int i, j, k;
};

int cherryPickupDetail(vector<vector<int>> &grid) {
  int M = grid.size();
  int N = grid[0].size();

  vector<vector<vector<int>>> dp(M, vector<vector<int>>(N, vector<int>(N, -1)));
  // vector<vector<vector<int>>> pj(M, vector<vector<int>>(N, vector<int>(N, -1)));
  // vector<vector<vector<int>>> pk(M, vector<vector<int>>(N, vector<int>(N, -1)));

  dp[0][0][N - 1] = grid[0][0] + grid[0][N - 1];

  for (int i = 1; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {

        int mx = -1;
        for (int m = -1; m <= 1; ++m) {
          for (int n = -1; n <= 1; ++n) {
            int alice = j + m;
            int bob = k + n;

            if (alice < 0 || alice >= N || bob < 0 || bob >= N)
              continue;
            // mx = max(dp[i - 1][alice][bob], mx);

            if (dp[i - 1][alice][bob] > mx) {
              mx = dp[i - 1][alice][bob];
              // pj[i][j][k] = alice;
              // pk[i][j][k] = bob;
            }
          }
        }
        if (mx == -1)
          continue;

        if (i == 1) {
          // pj[i][j][k] = 0;
          // pk[i][j][k] = N - 1;
          mx = dp[0][0][N - 1];
        }

        dp[i][j][k] = mx + grid[i][j] + grid[i][k];
        if (j == k) {
          dp[i][j][k] -= grid[i][j];
        }
      }
    }
  }

  // finding the answer;
  // int destJ = -1, destK;
  int ans = -1;
  for (int j = 0; j < N; ++j) {
    for (int k = 0; k < N; ++k) {
      // ans = max(ans, dp[M - 1][j][k]);
      if (dp[M - 1][j][k] > ans) {
        ans = dp[M - 1][j][k];
        // destJ = j;
        // destK = k;
      }
    }
  }

  // Reconstructing the path;
  // list<pos> path;
  // pos curr = {M - 1, destJ, destK};
  // path.push_front(curr);
  // while (curr.i != 0) {
  //   pos newCurr = {curr.i - 1, pj[curr.i][curr.j][curr.k],
  //                  pk[curr.i][curr.j][curr.k]};
  //   path.push_front(newCurr);
  //   curr = newCurr;
  // }

  // cout << M << " " << N << endl;
  // for (int i = 0; i < M; ++i) {
  //   for (int j = 0; j < N; ++j) {
  //     cout << grid[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  //
  // // print the path;
  // for (auto ps : path) {
  //   cout << " (" << ps.i << ", " << ps.j << ") "
  //        << "(" << ps.i << ", " << ps.k << " ) " << endl;
  // }
  //
  return ans;
}

int cherryPickup(vector<vector<int>> &grid) {
  int M = grid.size();
  int N = grid[0].size();

  // vector<vector<vector<int>>> dp(M, vector<vector<int>>(N, vector<int>(N, -1)));

  vector<vector<int>> DP(N, vector<int>(N, -1));
  vector<vector<int>> NDP(N, vector<int>(N, -1));

  // dp[0][0][N - 1] = grid[0][0] + grid[0][N - 1];
  DP[0][N-1] = grid[0][0] + grid[0][N-1];

  for (int i = 1; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {

        int mx = -1;
        for (int m = -1; m <= 1; ++m) {
          for (int n = -1; n <= 1; ++n) {
            int alice = j + m;
            int bob = k + n;

            if (alice < 0 || alice >= N || bob < 0 || bob >= N)
              continue;

            // if (dp[i - 1][alice][bob] > mx) {
            //   mx = dp[i - 1][alice][bob];
            // }
            if (DP[alice][bob] > mx) mx = DP[alice][bob];
          }
        }
        if (mx == -1)
          continue;

        // if (i == 1) {
        //   mx = dp[0][0][N - 1];
        // }
        
        if (i == 1) {
          mx = DP[0][N-1];
        }

        // dp[i][j][k] = mx + grid[i][j] + grid[i][k];
        NDP[j][k] = mx + grid[i][j] + grid[i][k];
        if (j == k) {
          // dp[i][j][k] -= grid[i][j];
          NDP[j][k] -= grid[i][j];
        }
      }
    }
    swap(DP, NDP);
  }

  int ans = -1;
  for (int j = 0; j < N; ++j) {
    for (int k = 0; k < N; ++k) {
      // if (dp[M - 1][j][k] > ans) {
      //   ans = dp[M - 1][j][k];
      // }
      if (DP[j][k] > ans) ans = DP[j][k];
    }
  }

  return ans;
}


int main() {
  int T;
  cin >> T;

  while (T--) {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> grid[i][j];
      }
    }

    auto ans = cherryPickup(grid);
    cout << ans << endl;
  }
}
