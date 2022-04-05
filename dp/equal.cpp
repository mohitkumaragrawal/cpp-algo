#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000];

int solve(vector<int>& arr, int N) {
  int m = *min_element(arr.begin(), arr.end());
  int ans = INT_MAX;

  for (int i = 0; i <= m; ++i) {
    int newAns = 0;
    for (auto el: arr) {
      newAns += dp[el-i];
    }
    ans = min(ans, newAns);
  }
  
  return ans;
}

int main() {
  freopen("equal.txt", "r", stdin);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 2;
  dp[4] = 2;
  for (int i = 5; i < 1000; ++i) {
    dp[i] = 1 + min({dp[i-1], dp[i-2], dp[i-5]});
  }

  int t;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> arr(n);
    for (int & i: arr) cin >> i;
    cout << solve(arr, n) << endl;
  }
}