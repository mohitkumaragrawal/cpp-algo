#include <bits/stdc++.h>
using namespace std;

int lcs(const string& A, const string& B, int m, int n) {
  if (m == 0 || n == 0) return 0;

  int ans = lcs(A, B, m-1, n);
  ans = max(ans, lcs(A, B, m, n-1));
  
  if (A[m-1] == B[n-1]) {
    ans = max(ans, 1 + lcs(A, B, m-1, n-1));
  }
  return ans;
}

int lcs_memopt(const string& A, const string& B) {
  int M = A.size();
  int N = B.size();

  // vector<vector<int>> dp(M+1, vector<int>(N+1));
  vector<int> dp(N+1, 0), ndp(N+1);

  for (int i = 1; i <= M; ++i) {
    ndp[0] = 0;
    for (int j = 1; j <= N; ++j) {
      if (A[i-1] == B[j-1]) {
        ndp[j] = 1 + dp[j-1];
      } else {
        ndp[j] = max(dp[j], ndp[j-1]);
      }
    }

    swap(dp, ndp);
  }

  return dp[N];
}

int lcs_dp(const string& A, const string& B) {
  int M = A.size();
  int N = B.size();

  vector<vector<int>> dp(M+1, vector<int>(N+1));
  
  for (int i = 0; i <= M; ++i) dp[i][0] = 0;
  for (int j = 1; j <= N; ++j) dp[0][j] = 0;

  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= N; ++j) {
      int val = dp[i-1][j];
      val = max(val, dp[i][j-1]);

      if (A[i-1] == B[j-1]) {
        val = max(val, 1 + dp[i-1][j-1]);
      }
      dp[i][j] = val;
    }
  }

  for (int i = 0; i < dp.size(); ++i) {
    for (int j = 0; j < dp[i].size(); ++j) {
      cout << dp[i][j] << " ";
    } cout << endl;
  }

  return dp[M][N];
}

int longestCommonSubstring(const string& A, const string& B) {
  int M = A.size();
  int N = B.size();

  vector<vector<int>> dp(M+1, vector<int>(N+1));
  
  for (int i = 0; i <= M; ++i) dp[i][0] = 0;
  for (int j = 1; j <= N; ++j) dp[0][j] = 0;

  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (A[i-1] == B[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      } else {
        dp[i][j] = 0;
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (dp[i][j] > ans) ans = dp[i][j];
    }
  }
  return ans;
}


int main() {
  string A, B;
  cin >> A >> B;

  cout << lcs_dp(A, B) << endl;
  cout << longestCommonSubstring(A, B) << endl;
}
