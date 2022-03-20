#include <iostream>
#include <vector>
using namespace std;

#define int long long

// using memoized recursion dynamic programming;
int countWays(vector<int>& A, int N, int S, vector<vector<int>>& dp) {
    if (dp[N][S] != -1) return dp[N][S];
    
  if (S == 0) return dp[N][S]=1;
  if (N == 0) return dp[N][S]=0;

  int Key = A[N-1];
  
  int Result = countWays(A, N-1, S, dp);
  int k = 1;
  while ((S- k * Key) >= 0) {
    Result += countWays(A, N-1, (S- k*Key), dp);
    ++k;
  }
  return dp[N][S]=Result;
}

int32_t main() {
  int N, S;
  cin >> S >> N;
  vector<int> A(N);
  for (int& i: A) cin >> i;
  
  vector<vector<int>> dp(N+1, vector<int>(S+1, -1));
  cout << countWays(A, A.size(), S, dp);
}