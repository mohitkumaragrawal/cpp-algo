#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

ll n, m;
ll k, x;
vector<vector<ll>> edges;

ll dp[100005][11][3];

void dfs(ll curr, ll par) {
  for (ll child : edges[curr]) {
    if (child != par) dfs(child, curr);
  }

  ll sub_dp[edges[curr].size() + 1][12];

  /* flag = 0 */
  {
    memset(sub_dp, 0, sizeof(sub_dp));
    sub_dp[0][0] = 1;
    ll cnt = 0;
    for (ll child : edges[curr]) {
      if (child != par) {
        for (ll cur_taken = 0; cur_taken <= x; ++cur_taken) {
          for (ll take = 0; take <= x - cur_taken; ++take) {
            ll tot = cur_taken + take;
            ll val =
                dp[child][take][0] + dp[child][take][1] + dp[child][take][2];
            sub_dp[cnt + 1][tot] =
                (sub_dp[cnt + 1][tot] + val * sub_dp[cnt][cur_taken]) % MOD;
          }
        }
        ++cnt;
      }
    }
    for (ll y = 0; y <= x; ++y) {
      dp[curr][y][0] = ((k - 1) * sub_dp[cnt][y]) % MOD;
    }
  }

  /* flag = 1 */
  {
    memset(sub_dp, 0, sizeof(sub_dp));
    sub_dp[0][0] = 1;
    ll cnt = 0;
    for (ll child : edges[curr]) {
      if (child != par) {
        for (ll cur_taken = 0; cur_taken <= x; ++cur_taken) {
          for (ll take = 0; take <= x - cur_taken; ++take) {
            ll tot = cur_taken + take;
            ll val = dp[child][take][0];
            sub_dp[cnt + 1][tot] =
                (sub_dp[cnt + 1][tot] + val * sub_dp[cnt][cur_taken]) % MOD;
          }
        }
        ++cnt;
      }
    }
    for (ll y = 0; y < x; ++y) {
      dp[curr][y + 1][1] = sub_dp[cnt][y] % MOD;
    }
  }

  /* flag = 2 */
  {
    memset(sub_dp, 0, sizeof(sub_dp));
    sub_dp[0][0] = 1;
    ll cnt = 0;
    for (ll child : edges[curr]) {
      if (child != par) {
        for (ll cur_taken = 0; cur_taken <= x; ++cur_taken) {
          for (ll take = 0; take <= x - cur_taken; ++take) {
            ll tot = cur_taken + take;
            ll val = dp[child][take][0] + dp[child][take][2];
            sub_dp[cnt + 1][tot] =
                (sub_dp[cnt + 1][tot] + val * sub_dp[cnt][cur_taken]) % MOD;
          }
        }
        ++cnt;
      }
    }
    for (ll y = 0; y <= x; ++y) {
      dp[curr][y][2] = ((m - k) * sub_dp[cnt][y]) % MOD;
    }
  }
}

void solve() {
  cin >> n >> m;
  edges.resize(n);
  for (ll i = 0; i < n - 1; ++i) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  cin >> k >> x;

  dfs(0, -1);
  ll ans = 0;
  for (ll i = 0; i <= x; ++i) {
    for (ll j = 0; j < 3; ++j) {
      ans = (ans + dp[0][i][j]) % MOD;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  solve();
}
