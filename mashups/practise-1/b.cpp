#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll wt[505][505], dist[505][505];
bool inserted[505];
const ll INF = 1e17;

ll n;

void insert_vertex(ll v) {
  inserted[v] = true;
  dist[v][v] = 0;

  for (ll i = 1; i <= n; ++i) {
    if (!inserted[i]) continue;

    dist[v][i] = wt[v][i];
    dist[i][v] = wt[i][v];
  }

  for (ll i = 1; i <= n; ++i) {
    if (!inserted[i]) continue;
    for (ll j = 1; j <= n; ++j) {
      if (!inserted[j]) continue;
      dist[v][j] = min(dist[v][j], dist[v][i] + dist[i][j]);
    }
  }

  for (ll i = 1; i <= n; ++i) {
    if (!inserted[i]) continue;
    for (ll j = 1; j <= n; ++j) {
      if (!inserted[j]) continue;
      dist[j][v] = min(dist[j][v], dist[j][i] + dist[i][v]);
    }
  }

  for (ll i = 1; i <= n; ++i) {
    if (!inserted[i]) continue;
    for (ll j = 1; j <= n; ++j) {
      if (!inserted[j]) continue;
      dist[i][j] = min(dist[i][j], dist[i][v] + dist[v][j]);
    }
  }
}

void solve() {
  cin >> n;

  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= n; ++j) dist[i][j] = INF;
  }

  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= n; ++j) {
      cin >> wt[i][j];
    }
  }

  vector<ll> q(n);
  for (ll i = 0; i < n; ++i) cin >> q[i];

  vector<ll> ans(n);
  for (ll idx = n - 1; idx >= 0; --idx) {
    ll v = q[idx];
    insert_vertex(v);

    ll res = 0;
    for (ll i = 1; i <= n; ++i) {
      for (ll j = 1; j <= n; ++j) {
        if (inserted[i] && inserted[j]) res += dist[i][j];
      }
    }

    ans[idx] = res;
  }

  for (ll i = 0; i < n; ++i) cout << ans[i] << " ";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
