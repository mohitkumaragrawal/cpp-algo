#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, k;
  cin >> N >> k;

  vector<int> c(N), active(N);
  for (int& i: c) cin >> i;
  for (int& i: active) cin >> i;

  int activeSum = 0;
  for (int i = 0; i < N; ++i) {
    if (active[i] == 1) activeSum += c[i];
  } 

  vector<int> dp(N - k + 1);
  dp[0] = activeSum;
  for (int i = 0; i < k; ++i) {
    if (active[i] == 0) {
      dp[0] += c[i];
    }
  }
  int ans = dp[0];

  for (int i = 1; i <= (N-k); ++i) {
    int newEl = i + k - 1;
    dp[i] = dp[i-1];
    if (active[newEl] == 0){
      dp[i] += c[newEl];
    }
    if (active[i-1] == 0) {
      dp[i] -= c[i-1];
    }

    ans = max(ans, dp[i]);
  }

  cout << ans << endl;
}