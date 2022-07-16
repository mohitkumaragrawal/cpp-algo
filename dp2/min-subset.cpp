#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int> &arr, int N) {
  int SUM = 0;
  for (int x : arr)
    SUM += x;

  vector<bool> dp(SUM + 1, false), ndp(SUM+1, false);

  dp[0] = true;
  dp[arr[0]] = true;

  for (int i = 1; i < N; ++i) {
    ndp[0] = true;
    for (int j = 1; j <= SUM; ++j) {
      bool not_take = dp[j];
      bool take = false;
      if (j >= arr[i]) {
        take = dp[j - arr[i]];
      }

      ndp[j] = take | not_take;
    }

    swap(dp, ndp);
  }
  int onesum = SUM / 2;
  int reqsum = -1;
  for (int i = 0; onesum + i <= SUM; ++i) {
    if (dp[onesum + i]) {
      reqsum = onesum + i;
      break;
    }
  }

  return abs(SUM - 2 * reqsum);
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int &i : arr)
      cin >> i;

    cout << minSubsetSumDifference(arr, N) << endl;
  }
}
