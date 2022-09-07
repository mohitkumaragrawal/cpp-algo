#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e+9 + 7;

vector<vector<vector<ll>>> dp(100001, vector<vector<ll>>(11, vector<ll>(2, 0)));
vector<vector<int>> graph(100001);
vector<int> parent(100001, -1);
int N, M, K, X;

void compute_dfs(int node) {
  int p = parent[node];

  bool is_leaf = false;
  if (graph[node].size() == 1 && p != -1) {
    is_leaf = true;
  }

  for (auto child : graph[node]) {
    if (child == p) continue;

    parent[child] = node;
    compute_dfs(child);
  }

  if (is_leaf) {
  }
}

int main() {
  cin >> N >> M;

  for (int _ = 1; _ < N; ++_) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  cin >> K >> X;

  compute_dfs(1);

  // calculate the answer;
  ll ans = 0;
  for (int x = 0; x <= X; ++x) {
    ans += dp[1][x][0] + dp[1][x][1];
    ans %= MOD;
  }

  cout << ans << endl;
}