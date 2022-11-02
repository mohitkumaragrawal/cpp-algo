#include <bits/stdc++.h>
#define all(x) begin(x), end(x)

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll arr[2005];
ll dp[2005][2005];

void solve() {
  ll N;
  cin >> N;

  for (ll i = 0; i < N; ++i) cin >> arr[i];

  for (ll i = 0; i <= N; ++i) {
    for (ll j = 0; j <= N; ++j) {
      dp[i][j] = -1;
    }
  }
  for (ll i = 0; i <= N; ++i) {
    dp[i][0] = 0;
  }

  for (ll i = 1; i <= N; ++i) {
    for (ll j = 1; j <= N; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (dp[i - 1][j - 1] != -1) {
        dp[i][j] = max(dp[i][j], arr[i - 1] + dp[i - 1][j - 1]);
      }
    }
  }

  ll ans = 0;
  for (ll j = 1; j <= N; ++j) {
    if (dp[N][j] >= 0) ans = j;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}
