#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct edge {
  ll w, u, v;
};
bool operator<(const edge& a, const edge& b) { return a.w < b.w; }

vector<edge> elist;
vector<ll> a;

ll parent[200005];
ll dsu_size[200005];

ll find_set(ll x) {
  if (parent[x] == x) return x;
  return parent[x] = find_set(parent[x]);
}

void union_set(ll x, ll y) {
  ll p1 = find_set(x);
  ll p2 = find_set(y);
  if (p1 == p2) return;

  if (dsu_size[p2] > dsu_size[p1]) swap(p1, p2);
  parent[p2] = p1;
  dsu_size[p1] += dsu_size[p2];
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  iota(begin(parent), end(parent), 0);
  fill(begin(dsu_size), end(dsu_size), 1);
  ll N, M;
  cin >> N >> M;

  a.resize(N);
  for (auto i = 0; i < N; ++i) {
    cin >> a[i];
  }

  auto mitr = min_element(a.begin(), a.end());
  int midx = mitr - a.begin();
  for (auto itr = a.begin(); itr != a.end(); ++itr) {
    if (itr == mitr) continue;
    int j = itr - a.begin();
    elist.push_back({(*mitr + *itr), midx, j});
  }

  for (int i = 0; i < M; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    elist.push_back({w, u, v});
  }

  sort(elist.begin(), elist.end());

  ll ans = 0;
  for (auto e : elist) {
    if (find_set(e.u) == find_set(e.v)) continue;
    ans += e.w;
    union_set(e.u, e.v);
  }

  cout << ans << endl;
}