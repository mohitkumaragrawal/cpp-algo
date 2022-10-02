#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct edge {
  ll w, u, v;
};
bool operator<(const edge& a, const edge& b) { return a.w < b.w; }
bool operator>(const edge& a, const edge& b) { return a.w > b.w; }

ll N, M, K, ans;
ll B[100005];

vector<edge> elist;
vector<pair<ll, ll>> edges[100005];

ll parent[100005];
ll dsu_size[100005];
ll special[100005];
ll dp[100005];

void dfs(ll n, ll p, ll wt) {
  dp[n] = special[n];

  for (auto [w, v] : edges[n]) {
    if (v == p) continue;
    dfs(v, n, w);

    dp[n] += dp[v];
  }

  if (min(dp[n], K - dp[n]) > 0) {
    ans = max(ans, wt);
  }
}

ll find_set(ll x) {
  if (parent[x] == x) return x;
  return parent[x] = find_set(parent[x]);
}

void union_set(ll n1, ll n2) {
  ll p1 = find_set(n1), p2 = find_set(n2);
  if (p1 == p2) return;

  if (dsu_size[p1] < dsu_size[p2]) swap(p1, p2);
  parent[p2] = p1;
  dsu_size[p1] += dsu_size[p2];
}

void solve() {
  iota(begin(parent), end(parent), 0);

  cin >> N >> M >> K;
  for (int i = 0; i < K; ++i) {
    cin >> B[i];
    B[i]--;
    special[B[i]] = 1;
  }

  for (int i = 0; i < M; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    elist.push_back({w, u, v});
  }

  // Kruskal's algorithm;
  sort(elist.begin(), elist.end());
  for (auto [w, u, v] : elist) {
    if (find_set(u) == find_set(v)) continue;
    union_set(u, v);

    edges[u].push_back({w, v});
    edges[v].push_back({w, u});
  }

  dfs(0, -1, 0);
  for (int i = 0; i < K; ++i) cout << ans << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  solve();
}