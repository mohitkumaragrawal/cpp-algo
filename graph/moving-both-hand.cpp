#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

const ll INF = 1e+16;
ll N, M;

vector<vector<pair<ll, ll>>> G;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  cin >> N >> M;
  G.resize(2 * N + 1);

  for (ll i = 1; i <= N; ++i) {
    G[i].push_back({0, i + N});
  }

  for (ll i = 1; i <= M; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;

    G[u].push_back({w, v});
    G[v + N].push_back({w, u + N});
  }

  vector<ll> dist(2 * N + 1, INF);
  min_pq<pair<ll, ll>> q;

  q.push({0, 1});
  while (!q.empty()) {
    auto [d, node] = q.top();
    q.pop();

    if (dist[node] <= d) continue;
    dist[node] = d;

    for (auto [weight, child] : G[node]) {
      q.push({weight + d, child});
    }
  }

  for (ll i = 2; i <= N; ++i) {
    if (dist[i + N] == INF) dist[i + N] = -1;
    cout << dist[i + N] << " ";
  }
  cout << endl;
}
