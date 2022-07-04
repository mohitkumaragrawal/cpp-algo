#include <iostream>
#include <vector>

using namespace std;

int calculate_max_non_adjacent_sum(vector<int> &arr) {
  if (arr.size() == 1)
    return arr[0];

  vector<int> dp(arr.size());
  dp[0] = arr[0];
  dp[1] = max(arr[0], arr[1]);

  for (int i = 2; i < arr.size(); ++i) {
    dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
  }
  return dp[arr.size() - 1];
}

// Space optimized, if we don't consider space by arr, then space complexity is
// O(1), we used just a couple of variables;
int calc_mx_nonadj_sum_space(vector<int> &arr) {
  int N = arr.size();
  int a = arr[0];
  if (arr.size() == 1)
    return a;

  int b = max(arr[0], arr[1]);
  // b = 2, a = 2
  for (int i = 2; i <= N - 1; ++i) {
    int newb = max(b, a + arr[i]);
    a = b;
    b = newb;
  }
  return b;
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

    cout << calculate_max_non_adjacent_sum(arr) << " "

         << calc_mx_nonadj_sum_space(arr) << endl;
  }
}
