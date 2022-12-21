#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;

int g[110][110];
ll dp[110][110];

void solve() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) scanf("%d", &g[i][j]);

  dp[1][1] = 2;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) {
      bool flag = 1;
      for (int k = 1; k <= i; k++) {
        if (g[k][i] == 1 && k < j) flag = 0;
        if (g[k][i] == 2 && k >= j) flag = 0;
      }
      dp[i][j] *= flag;
      dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
      dp[i + 1][i + 1] = (dp[i + 1][i + 1] + dp[i][j]) % mod;
    }

  ll ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + dp[n][i]) % mod;
  printf("%lld\n", ans);
}
signed main() {
  int T = 1;  // scanf("%d",&T);
  while (T--) solve();
  return 0;
}
