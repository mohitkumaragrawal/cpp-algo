#include <iostream>
#include <vector>

using namespace std;

using ull = uint64_t;

int main() {
  ull n, m;
  cin >> n >> m;

  vector<ull> coins(m);
  for (ull i = 0; i < m; ++i) cin >> coins[i];
  
  vector<ull> dp(n+1, 0);
  dp[0] = 1;

  for (ull i = 0; i < m; ++i) {
    for (ull j = coins[i]; j < n+1; ++j) {
      if (j < coins[i]) continue;

      dp[j] += dp[j - coins[i]];
    }
  }
  cout << dp[n] << endl;
}