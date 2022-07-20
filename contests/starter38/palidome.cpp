#include <bits/stdc++.h>
using namespace std;

void printLCS(const string& A, const string& B) {
  int M = A.size();
  int N = B.size();

  vector<vector<int>> dp(M+1, vector<int>(N + 1));
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

  string result;
  int x = M, y = N;
  while (x > 0 &&  y > 0) {
    if (A[x-1] == B[y-1]) {
      result.push_back(A[x-1]);
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
  reverse(result.begin(), result.end());
  cout << result << endl;
}

int main() {
  int T;
  cin >> T;

  while(T--) {
    int n;
    string s;
    cin >> n >> s;

    string b = s;
    reverse(b.begin(), b.end());

    printLCS(s, b);
  }
}