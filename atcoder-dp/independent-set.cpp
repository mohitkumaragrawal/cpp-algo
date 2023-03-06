#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n;
vector<vector<ll>> G;

const ll MOD = 1e9 + 7;

ll dp[100005][2];

void dfs(ll cur, ll par) {
  dp[cur][0] = dp[cur][1] = 1;

  for (ll child : G[cur]) {
    if (child == par) continue;

    dfs(child, cur);

    dp[cur][0] *= dp[child][0] + dp[child][1];
    dp[cur][1] *= dp[child][0];

    dp[cur][0] %= MOD;
    dp[cur][1] %= MOD;
  }
}

void solve() {
  cin >> n;
  G.resize(n);

  for (ll i = 0; i < n - 1; ++i) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;

    G[x].push_back(y);
    G[y].push_back(x);
  }

  dfs(0, -1);

  ll ans = (dp[0][0] + dp[0][1]) % MOD;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
