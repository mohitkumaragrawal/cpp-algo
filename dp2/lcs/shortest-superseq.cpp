#include <bits/stdc++.h>
using namespace std;

string findLCS(const string& A, const string& B) {
  int M = A.size();
  int N = B.size();

  vector<vector<int>> dp(M+1, vector<int>(N+1));
  for (int i = 0; i <= M; ++i) dp[i][0] = 0;
  for (int j = 0; j <= N; ++j) dp[0][j] = 0;

  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (A[i-1] == B[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  string lcs;
  int x = M, y = N;
  while (x > 0 && y > 0) {
    if (A[x-1] == B[y-1]) {
      lcs.push_back(A[x-1]);
      x--;
      y--;
      continue;
    }

    if (dp[x-1][y] > dp[x][y-1]) {
      x--;
    } else {
      y--;
    }
  }
  reverse(lcs.begin(), lcs.end());
  return lcs;
}

void printShortestSupersequence(const string& A, const string& B) {
  auto lcs = findLCS(A, B);

  int i = 0, j = 0, k = 0;
  string super;
  while (k < lcs.size()) {
    if (A[i] != lcs[k]) {
      super.push_back(A[i]);
      i++;
    } else if (B[j] != lcs[k]) {
      super.push_back(B[j]);
      j++;
    } else {
      super.push_back(lcs[k]);
      i++; j++; k++;
    }
  }

  while (i < A.size()) {
    super.push_back(A[i]);
    i++;
  }
  while (j < B.size()) {
    super.push_back(B[j]);
    j++;
  }

  cout << super << endl;
}

void printShortestSupersequence2(const string& A, const string& B) {
  int M = A.size();
  int N = B.size();
  vector<vector<int>> dp(M + 1, vector<int>(N + 1));
  for (int i = 0; i <= M; ++i) dp[i][0] = 0;
  for (int j = 1; j <= N; ++j) dp[0][j] = 0;

  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (A[i-1] == B[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  string scs;
  int x = M;
  int y = N;

  while (x > 0 && y > 0) {
    if (A[x-1] == B[y-1]) {
      scs.push_back(A[x-1]);
      x--;
      y--;
      continue;
    }

    if (dp[x][y-1] > dp[x-1][y]) {
      scs.push_back(B[y-1]);
      y--;
    } else {
      scs.push_back(A[x-1]);
      x--;
    }
  }
  while (x > 0) {
    scs.push_back(A[x-1]);
    x--;
  }
  while (y > 0) {
    scs.push_back(B[y-1]);
    y--;
  }

  reverse(scs.begin(), scs.end());
  cout << scs << endl;
}

int main() {
  string A, B;
  cin >> A >> B;

  printShortestSupersequence(A, B);
  printShortestSupersequence2(A, B);
}
