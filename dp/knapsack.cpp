#include <iostream>
#include <vector>

using namespace std;

// dp[l][c], l is starting index, c is the capacity left;
// dp[l][c] = max{ dp[l+1, c], (v[l] + dp[l+1, c-w[l]]) if w[l] <= c }, ans = dp[0][C]
// dp[N-1][i] = 0 if w[N-1] > i else v[N-1]
// dp[j][0] = 0

int knapsack(vector<int>& wt, vector<int>& val, int capacity, int l) {
  if (capacity <= 0) return 0;
  int r = wt.size() - 1;

  if (l == r) {
    if (capacity >= wt[l]) {
      return val[l];
    }
    return 0;
  }

  int without_l = knapsack(wt, val, capacity, l+1);

  int with_l = 0;
  if (capacity >= wt[l]) {
    with_l = val[l] + knapsack(wt, val, capacity-wt[l], l+1);
  }
  return max(with_l, without_l);
}

int knapsack_topdown(vector<int>& wt, vector<int>& val, int W) {
  auto N = wt.size();
  vector<vector<int>> dp(N, vector<int>(W+1));

  for (int i = 0; i < N; ++i) {
    dp[i][0] = 0;
  }

  for (int i = 0; i <= W; ++i) {
    if (i >= wt[N-1]) {
      dp[N-1][i] = val[N-1];
    } else{
      dp[N-1][i] = 0;
    }
  }

  for (int i = N-2; i >= 0; --i) {
    for (int j = 1; j <= W; ++j) {
      if (wt[i] > j) {
        dp[i][j] = dp[i+1][j];
      } else {
        dp[i][j] = max(dp[i+1][j], val[i] + dp[i+1][j-wt[i]]);
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= W; ++j) {
      cout << dp[i][j] << " ";
    } cout << endl;
  }

  return dp[0][W];
}

int main() {
  int N;
  cin >> N;
  vector<int> wt(N), val(N);
  for (auto& el: wt) cin >> el;
  for (auto& el: val) cin >> el;

  int capacity;
  cin >> capacity;

  auto result = knapsack(wt, val, capacity, 0);
  cout << result << endl;

  auto result_2 = knapsack_topdown(wt, val, capacity);
  cout << result_2 << endl;
}