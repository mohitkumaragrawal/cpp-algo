#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
ll N;
string str;
vector<vector<ll>> G;
vector<ll> toposort;

ll max_path_value(char ch) {
  vector<ll> dp(N, 0);
  vector<ll> reverse_map(N + 1);
  for (ll i = 0; i < N; ++i) {
    reverse_map[toposort[i]] = i;
  }
  for (ll i = 0; i < N; ++i) {
    ll nd = toposort[i];

    if (str[nd - 1] == ch) {
      dp[i]++;
    }

    for (ll child : G[nd]) {
      ll child_idx = reverse_map[child];

      dp[child_idx] = max(dp[child_idx], dp[i]);
    }
  }

  return *max_element(dp.begin(), dp.end());
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll M;
  cin >> N >> M;
  cin >> str;

  G.resize(N + 1);
  vector<ll> indegree(N + 1, 0);

  for (int i = 1; i <= M; ++i) {
    ll x, y;
    cin >> x >> y;
    G[x].push_back(y);
    indegree[y]++;
  }

  queue<ll> q;

  for (ll i = 1; i <= N; ++i) {
    if (indegree[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    ll nd = q.front();
    q.pop();
    toposort.push_back(nd);

    for (ll child : G[nd]) {
      indegree[child]--;
      if (indegree[child] == 0) q.push(child);
    }
  }

  if (toposort.size() != N) {
    cout << -1 << endl;
    return 0;
  }

  ll ans = 0;

  for (char c = 'a'; c <= 'z'; ++c) {
    ll path_value = max_path_value(c);
    if (path_value > ans) {
      ans = path_value;
    }
  }

  cout << ans << endl;
}
