#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct edge {
  edge(ll from, ll to, ll weight) : from(from), to(to), weight(weight) {}
  ll from, to, weight;
};

bool operator<(const edge& a, const edge& b) { return a.weight < b.weight; }

vector<ll> parent;
vector<ll> sz;

ll find_set(ll nd) {
  if (parent[nd] == nd) return nd;

  return parent[nd] = find_set(parent[nd]);
}

ll union_set(ll a, ll b) {
  ll p1 = find_set(a);
  ll p2 = find_set(b);

  if (sz[p1] < sz[p2]) {
    swap(p1, p2);
  }

  parent[p2] = p1;
  sz[p1] += sz[p2];
  return p1;
}

bool is_connected(ll a, ll b) { return find_set(a) == find_set(b); }

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll N, M;
  cin >> N >> M;

  parent.resize(N + 1);
  sz.assign(N + 1, 1);

  for (ll i = 1; i <= N; ++i) parent[i] = i;

  vector<edge> edges;
  for (ll i = 1; i <= M; ++i) {
    ll x, y, w;
    cin >> x >> y >> w;
    edges.push_back(edge(x, y, w));
  }

  sort(edges.begin(), edges.end());

  ll ans = 0;
  for (auto ed : edges) {
    if (is_connected(ed.from, ed.to)) continue;

    union_set(ed.from, ed.to);
    ans += ed.weight;
  }
  cout << ans << endl;
}