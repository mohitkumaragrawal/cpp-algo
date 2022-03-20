#include <iostream>
#include <vector>

using namespace std;

int target_sum(vector<int>& arr, int target) {
  auto N=arr.size();
  int S = 0;
  for (auto i: arr) S+=abs(i);

  if (abs(target) > abs(S)) return 0;

  int K = (2*S + 1);
  vector<vector<int>> dp(N, vector<int>(K));

  for (int i = -S; i <= S; ++i) {
    int idx = i;
    if (idx < 0) idx += K;
    if (abs(i) == arr[N-1]) {
      dp[N-1][idx] = 1;
    } else {
      dp[N-1][idx] = 0;
    }
  }

  for (int i = (N-2); i >= 0; --i) {
    for (int j = (-S); j <= S; ++j) {
      int idx = j;
      if (idx < 0) {
        idx += K;
      }

      int res = 0;
      int s1 = j - arr[i];
      int s2 = j + arr[i];

      if (s1 >= -S && s1 <= S) {
        if (s1 < 0) s1 += K;
        res += dp[i+1][s1];
      }

      if (s2 >= -S && s2 <= S) {
        if (s2 < 0) s2 += K;
        res += dp[i+1][s2];
      }

      dp[i][idx] = res;
    }
  }
  if (target < 0) target += K;

  return dp[0][target];
}

int main() {
  int N;
  cin >> N;

  vector<int> arr(N);
  for (int &i: arr) cin >> i;

  int target;
  cin >> target;

  cout << target_sum(arr, target) << endl;
}