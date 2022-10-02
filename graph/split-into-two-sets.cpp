#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

vector<vector<int>> G(200001);
vector<bool> visited(200001, false);

void solve() {
  int N;
  cin >> N;

  for (int i = 1; i <= N; ++i) {
    G[i].clear();
    visited[i] = false;
  }

  bool success = true;
  for (int i = 1; i <= N; ++i) {
    int x, y;
    cin >> x >> y;

    if (x == y) {
      success = false;
    }

    G[x].push_back(y);
    G[y].push_back(x);
  }

  function<int(int)> cycle_dfs = [&](int node) -> int {
    int result = 1;
    visited[node] = true;
    if (G[node].size() > 2) {
      success = false;
      return 0;
    }

    for (auto ch : G[node]) {
      if (!success) break;
      if (!visited[ch]) {
        result += cycle_dfs(ch);
      }
    }
    return result;
  };

  for (int i = 1; i <= N && success; ++i) {
    if (visited[i]) continue;

    int cycle = cycle_dfs(i);
    if (cycle % 2 != 0) {
      // odd length cycle
      success = false;
    }
  }

  if (success) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}