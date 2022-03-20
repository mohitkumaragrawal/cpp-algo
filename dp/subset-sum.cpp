#include <iostream>
#include <vector>

using namespace std;
bool subset_sum(vector<int>& A, int S) {
  int N = A.size();
  vector<vector<int>> dp(N, vector<int>(S+1));

  for (int i = 0; i < N; ++i) {
    dp[i][0] = 1;
  }

  for (int j = 1; j <= S; ++j) {
    dp[N-1][j] = (A[N-1] == j) ? 1 : 0;
  }

  for (int i = N-2; i >= 0; --i) {
    for (int j = 1; j <= S; ++j) {
      if (j - A[i] < 0) {
        dp[i][j] = dp[i+1][j];
        continue;
      }
      dp[i][j] = dp[i+1][j-A[i]] | dp[i+1][j];
    }
  }

  for (int i = 0; i < dp.size(); ++i) {
    for (int j = 0; j < dp[i].size(); ++j) {
      cout << dp[i][j] <<" ";
    }cout << endl;
  }

  return dp[0][S] == 1;
}

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int& i: A) cin >> i;
  
  while (true) {
    int S; cin >> S;
    if (subset_sum(A, S)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}