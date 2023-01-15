#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n;
vector<vector<ll>> G;
ll clr[200005];

ll down[200005], dp[200005], up[200005];

void dfs_down(ll cur, ll par) {
  ll child_count = 0;
  for (ll ch : G[cur]) {
    if (ch != par) child_count++;
  }

  down[cur] = clr[cur];

  if (child_count == 0) {
    return;
  }

  for (ll ch : G[cur]) {
    if (ch == par) continue;
    dfs_down(ch, cur);

    down[cur] += max(down[ch], 0LL);
  }
}

void dfs_up(ll cur, ll par) {
  ll val = up[cur] + clr[cur];
  for (ll child : G[cur]) {
    if (child != par) val += max(down[child], 0LL);
  }

  for (ll child : G[cur]) {
    if (child == par) continue;

    up[child] = val - max(down[child], 0LL);
    up[child] = max(up[child], 0LL);

    dfs_up(child, cur);
  }
}

void solve() {
  cin >> n;

  for (ll i = 0; i < n; ++i) {
    cin >> clr[i];
    clr[i] = (clr[i] == 1) ? 1 : -1;
  }

  G.resize(n + 1);

  for (ll i = 0; i < n - 1; ++i) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs_down(0, -1);
  dfs_up(0, -1);

  for (ll i = 0; i < n; ++i) {
    cout << down[i] + up[i] << " \n"[i == n - 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
