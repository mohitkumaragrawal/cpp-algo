#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

int n;
vector<vector<int>> G;
string s;

int dp[2005][2005];

void solve() {
  cin >> n;

  G.clear();
  G.resize(n);

  cin >> s;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) dp[i][j] = 0;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for (int i = 0; i < n; ++i) dp[i][i] = 1;

  queue<tuple<int, int, int, int>> q;
  vector<vector<bool>> vis(n, vector<bool>(n, false));

  for (int i = 0; i < n; ++i) {
    for (int j : G[i]) {
      dp[i][j] = 1;
      if (s[i] == s[j]) dp[i][j] = 2;

      q.push({i, j, i, j});
    }
  }

  while (!q.empty()) {
    auto [x, xx, yy, y] = q.front();
    q.pop();

    if (vis[x][y]) continue;
    vis[x][y] = true;

    // extend it;
    for (int u : G[y]) {
      if (u == yy) continue;

      if (s[x] == s[u]) {
        dp[x][u] = 2 + dp[xx][y];
      } else {
        dp[x][u] = max(dp[x][y], dp[xx][u]);
      }

      q.push({x, xx, y, u});
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
