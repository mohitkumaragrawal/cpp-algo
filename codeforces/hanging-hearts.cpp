#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll parent[100005];
vector<vector<ll>> G;

void solve() {
  ll n;
  cin >> n;

  for (ll i = 1; i < n; ++i) {
    cin >> parent[i];
    parent[i]--;
  }
  parent[0] = -1;

  vector<ll> dp(n), h(n, 1);

  for (ll i = n - 1; i >= 0; --i) {
    dp[i] = max(dp[i], h[i]);

    if (i != 0) {
      ll p = parent[i];
      dp[p] += dp[i];
      h[p] = max(h[p], 1 + h[i]);
    }
  }
  cout << dp[0] << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
