#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n, total;
ll w[100005], v[100005];
ll dp[101][100005];

// dp[i][j] = minimum weight required, considering only the first i items, in
// order to fill the knapsack with a value of j;
// dp[i][j] = min{dp[i-1][j], w[i-1]+dp[i-1][j - v[i-1]]}

void solve() {
  for (ll i = 0; i < 101; ++i) {
    for (ll j = 0; j < 100005; ++j) dp[i][j] = INT_MAX;
  }

  dp[0][0] = 0;

  cin >> n >> total;
  for (ll i = 0; i < n; ++i) cin >> w[i] >> v[i];

  for (ll i = 1; i <= n; ++i) {
    for (ll j = 0; j < 100005; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j >= v[i - 1]) {
        dp[i][j] = min(dp[i][j], w[i - 1] + dp[i - 1][j - v[i - 1]]);
      }
    }
  }

  ll ans = 0;
  for (ll j = 0; j < 100005; ++j) {
    if (dp[n][j] <= total) {
      ans = j;
    }
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}
