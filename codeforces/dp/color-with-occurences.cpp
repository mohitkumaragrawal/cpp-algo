#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

string t;
string s[11];
int n;
bool v[11][101];
int dp[105][11];
pair<int, int> parent[105][11];

int INF = 1e+9;

void solve() {
  cin >> t;
  cin >> n;
  for (ll i = 0; i < n; ++i) cin >> s[i];

  memset(v, 0, sizeof(v));

  for (int i = 0; i < 105; ++i) {
    for (int j = 0; j < 11; ++j) {
      dp[i][j] = INF;
      parent[i][j] = {-1, -1};
    }
  }
  for (int j = 0; j < 11; ++j) {
    dp[0][j] = 0;
    parent[0][j] = {0, 0};
  }

  for (int i = 0; i < n; ++i) {
    int k = 0;
    auto p = t.find(s[i], k);

    while (p != t.npos) {
      v[i][p + s[i].size() - 1] = true;

      k++;
      p = t.find(s[i], k);
    }
  }

  for (int i = 1; i <= t.size(); ++i) {
    for (int j = 1; j <= n; ++j) {
      // dp[i][j] = min(dp[i][j], dp[i][j - 1]);
      if (dp[i][j] > dp[i][j - 1]) {
        parent[i][j] = {i, j - 1};
        dp[i][j] = dp[i][j - 1];
      }

      if (!v[j - 1][i - 1]) {
        continue;
      }
      for (int k = 1; k <= s[j - 1].size(); ++k) {
        // dp[i][j] = min(dp[i][j], 1 + dp[i - k][n]);
        if (dp[i][j] > 1 + dp[i - k][n]) {
          dp[i][j] = 1 + dp[i - k][n];
          parent[i][j] = {i - k, n};
        }
      }
    }
  }

  if (dp[t.size()][n] == INF) {
    cout << -1 << endl;
    return;
  }

  auto pr = make_pair<int>(t.size(), n);
  vector<pair<int, int>> vpr;

  while (pr.first != 0) {
    auto npr = parent[pr.first][pr.second];

    if (pr.first != npr.first) {
      vpr.push_back(
          make_pair(pr.second, pr.first - s[pr.second - 1].size() + 1));
    }

    pr = npr;
  }

  cout << vpr.size() << endl;
  for (auto xpr : vpr) {
    cout << xpr.first << " " << xpr.second << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
