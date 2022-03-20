#include <vector>
#include <iostream>
using namespace std;

int calcProfit(int N, vector<int>& price) {
  vector<int> dp(N+1);
  dp[1] = price[1];

  for (int i = 2; i <= N; ++i) {
    for (int j = 1; j <= i/2; ++j) {
      dp[i] = max(dp[i-j]+dp[j],dp[i]);
    }
  }
  return dp[N];
}

int main() {
  int N; 
  cin >> N;

  vector<int> price(N+1);
  for (int i = 1; i <= N; ++i) {
    cin >> price[i];
  }

  auto max_profit = calcProfit(N, price);
  cout << max_profit << endl;
}