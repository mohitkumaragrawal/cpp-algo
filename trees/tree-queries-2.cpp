#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
#define NOT(cond) (!(cond))
using ll = long long;
using ull = unsigned long long;

ll parent[200005], st[200005], en[200005], depth[200005], n, m;
vector<vector<ll>> G;
ll TIME = -1;

void dfs(ll node, ll par, ll dep) {
  parent[node] = par;
  depth[node] = dep;
  st[node] = ++TIME;

  for (ll child : G[node]) {
    if (child != par) dfs(child, node, dep + 1);
  }

  en[node] = TIME;
}

void solve() {
  cin >> n >> m;
  G.resize(n);
  for (ll i = 0; i < n - 1; ++i) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  dfs(0, 0, 0);

  while (m--) {
    ll k;
    cin >> k;
    vector<ll> a(k);

    for (ll i = 0; i < k; ++i) {
      cin >> a[i];
      a[i]--;
      a[i] = parent[a[i]];
    }

    ll lowest = a[0];
    for (ll i = 1; i < k; ++i) {
      if (depth[lowest] < depth[a[i]]) lowest = a[i];
    }

    bool pos = 1;
    for (ll i = 0; i < k; ++i) {
      ll cur = a[i];
      if NOT (st[cur] <= st[lowest] && en[cur] >= en[lowest]) {
        pos = 0;
      }
    }

    cout << (pos ? "YES\n" : "NO\n");
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}
