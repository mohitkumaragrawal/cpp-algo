#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll INF = 1e+15;

ll N, M, K;
vector<vector<pair<ll, ll>>> G;

vector<ll> dijstra_sssp(ll nd) {
  vector<ll> result(N + 1, INF);

  using nd_pair = pair<ll, ll>;
  using min_priority_queue =
      priority_queue<nd_pair, vector<nd_pair>, greater<nd_pair>>;

  min_priority_queue pq;
  result[nd] = 0;
  pq.push({0, nd});

  while (!pq.empty()) {
    auto pr = pq.top();
    pq.pop();

    ll vertex = pr.second;
    ll dist = pr.first;

    for (auto child_pr : G[vertex]) {
      ll child_nd = child_pr.first;
      ll child_dist = dist + child_pr.second;

      if (result[child_nd] > child_dist) {
        result[child_nd] = child_dist;
        pq.push({child_dist, child_nd});
      }
    }
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> N >> M >> K;

  vector<ll> A(N + 1);
  for (ll i = 1; i <= N; ++i) cin >> A[i];

  G.resize(N + 1);
  for (ll i = 1; i <= M; ++i) {
    ll x, y, w;
    cin >> x >> y >> w;

    G[x].push_back({y, w});
    G[y].push_back({x, w});
  }

  for (ll i = 1; i <= N; ++i) {
    G[i].push_back({0, A[i]});
    G[0].push_back({i, A[i]});
  }

  for (ll i = 1; i <= K; ++i) {
    ll x;
    cin >> x;

    auto result = dijstra_sssp(x);
    for (ll j = 1; j < result.size(); ++j) {
      cout << result[j] << " ";
    }
    cout << endl;
  }
}