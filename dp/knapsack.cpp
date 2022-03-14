#include <iostream>
#include <vector>

using namespace std;

// dp[l][c], l is starting index, c is the capacity left;
// dp[l][c] = max{ dp[l+1, c], (v[l] + dp[l+1, c-w[l]]) if w[l] <= c }, ans = dp[0][C]
// dp[N-1][i] = 0 if w[N-1] > i else v[N-1]
// dp[j][0] = 0

int knapsack(vector<int>& wt, vector<int>& val, int capacity, int l, int r) {
  if (capacity <= 0) return 0;

  if (l == r) {
    if (capacity >= wt[l]) {
      return val[l];
    }
    return 0;
  }

  int without_l = knapsack(wt, val, capacity, l+1, r);

  int with_l = 0;
  if (capacity >= wt[l]) {
    with_l = val[l] + knapsack(wt, val, capacity-wt[l], l+1, r);
  }
  return max(with_l, without_l);
}

int main() {
  int N;
  cin >> N;
  vector<int> wt(N), val(N);
  for (auto& el: wt) cin >> el;
  for (auto& el: val) cin >> el;

  int capacity;
  cin >> capacity;

  auto result = knapsack(wt, val, capacity, 0, N-1);
  cout << result << endl;
}