#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, q;
vector<vector<ll>> adj;

ll blift[200005][18], depth[200005];

void binary_lifting_dfs(ll node, ll par, ll dpt) {
  depth[node] = dpt;
  for (ll child : adj[node]) {
    if (child == par) continue;
    blift[child][0] = node;
    for (ll i = 1; i < 18; ++i) {
      blift[child][i] = blift[blift[child][i - 1]][i - 1];
    }
    binary_lifting_dfs(child, node, dpt + 1);
  }
}

ll lift_node(ll node, ll amount) {
  ll y = node;
  for (ll i = 0; i < 18; ++i) {
    if ((amount >> i) & 1) {
      y = blift[y][i];
    }
  }
  return y;
}

ll lca(ll x, ll y) {
  if (depth[y] > depth[x]) {
    y = lift_node(y, depth[y] - depth[x]);
  } else if (depth[x] > depth[y]) {
    x = lift_node(x, depth[x] - depth[y]);
  }
  if (x == y) return x;

  for (ll i = 17; i >= 0; --i) {
    ll x1 = blift[x][i];
    ll y1 = blift[y][i];
    if (x1 != y1) {
      x = x1;
      y = y1;
    }
  }

  return blift[x][0];
}

bool compare(ll x, ll y) { return depth[x] < depth[y]; }

void process_query() {
  ll k;
  cin >> k;

  vector<ll> v(k);
  for (ll i = 0; i < k; ++i) {
    cin >> v[i];
    v[i]--;

    v[i] = blift[v[i]][0];
  }

  sort(v.begin(), v.end(), compare);

  while (v.size() > 1) {
    ll x = v[v.size() - 1];
    ll y = v[v.size() - 2];

    if (depth[y] > depth[x]) {
      y = lift_node(y, depth[y] - depth[x]);
    } else if (depth[x] > depth[y]) {
      x = lift_node(x, depth[x] - depth[y]);
    }

    if (x != y) {
      cout << "NO\n";
      return;
    }

    v.pop_back();
    v.pop_back();

    v.push_back(x);
  }

  cout << "YES\n";
}

int main() {
  cin >> n >> q;
  adj.resize(n);

  for (ll i = 0; i < n - 1; ++i) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for (ll i = 0; i < 18; ++i) {
    blift[0][i] = 0;
  }
  binary_lifting_dfs(0, -1, 0);

  while (q--) {
    process_query();
  }
}
