#include <bits/stdc++.h>
using namespace std;

bool recursive(int idx, int K, vector<int> &arr, vector<vector<int>> &dp) {
  if (K == 0)
    return true;

  if (idx < 0)
    return false;

  if (dp[idx][K] != -1)
    return dp[idx][K];

  bool not_take = recursive(idx - 1, K, arr, dp);
  bool take = false;
  if (arr[idx] <= K)
    take = recursive(idx - 1, K - arr[idx], arr, dp);

  return dp[idx][K] = take | not_take;
}

bool subsetSumToK(int N, int K, vector<int> &arr) {
  // vector<vector<int>> dp(N, vector<int>(K + 1, 0));

  vector<int> dp(K+1, 0), ndp(K+1, 0);
  dp[0] = 1;

  if (arr[0] <= K)
    dp[arr[0]] = 1;

  for (int i = 1; i < N; ++i) {
    ndp[0] = 1;
    for (int j = 1; j <= K; ++j) {
      bool not_take = dp[j];

      bool take = false;
      if (arr[i] <= j) {
        take = dp[j - arr[i]];
      }
      ndp[j] = take | not_take;
    }
    swap(ndp, dp);
  }
  return dp[K];
}

int main() {}
