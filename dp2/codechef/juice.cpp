#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e+12;

int main() {
  ll N;
  cin >> N;

  vector<ll> price(8, -1);
  for (int _ = 1; _ <= N; ++_) {
    ll p;
    string type;

    cin >> p >> type;
    int typeNum = 0;
    for (char ch: type) {
      if (ch == 'A') {
        typeNum |= 1;
      } else if (ch == 'B') {
        typeNum |= 2;
      } else if (ch == 'C') {
        typeNum |= 4;
      }
    }

    if (price[typeNum] == -1) {
      price[typeNum] = p;
    } else {
      price[typeNum] = min(price[typeNum], p);
    }
  }

  vector<vector<ll>> dp(8, vector<ll>(8, inf));
  dp[0][0] = 0;

  for (int i = 1; i <= 7; ++i) {
    for (int j = 0; j <= 7; ++j) {
      dp[i][j] = min( dp[i][j], dp[i-1][j] );

      if (price[i] == -1) continue;
      dp[i][j | i] = min(dp[i][j | i], price[i] + dp[i - 1][j]);
    }
  }

  if (dp[7][7] == inf) {
    cout << -1 << endl;
    return 0;
  }
  cout << dp[7][7] << endl;

  // vector<vector<int>> ways = {
  //   {1, 2, 4},
  //   {7},
  //   {3, 5},
  //   {3, 6},
  //   {5, 6},
  //   {3, 4},
  //   {5, 2},
  //   {6, 1}
  // };

  // int ans = -1;
  // for (auto& way: ways) {
  //   int p = 0;
  //   for (auto x: way) {
  //     if (price[x] == -1) {
  //       p = -1;
  //       break;
  //     }

  //     p += price[x];
  //   }

  //   if (p == -1) continue;
  //   if (ans == -1) {
  //     ans = p;
  //   } else {
  //     ans = min(ans, p);
  //   }
  // }
  // cout << ans << endl;
}
