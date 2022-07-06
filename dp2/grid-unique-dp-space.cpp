#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  cout << "Some text" << endl;
  while (T--) {
    int m, n;
    cin >> m >> n;

    vector<int> dp(n, 1);
    vector<int> ndp(n);
    ndp[0] = 1;
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        ndp[j] = ndp[j-1] + dp[j];
      }
      for (int j = 1; j < n; ++j) dp[j] = ndp[j];
    }

    cout << dp[n-1] << endl;
  }
}
