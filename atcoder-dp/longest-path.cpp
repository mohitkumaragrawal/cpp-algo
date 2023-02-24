#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n, m;
  vector<vector<ll>> G;

  cin >> n >> m;
  G.resize(n);

  vector<ll> inorder(n);

  for (ll i = 0; i < m; ++i) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    G[x].push_back(y);

    inorder[y]++;
  }

  vector<ll> topo;
  queue<ll> q;

  for (ll i = 0; i < n; ++i) {
    if (inorder[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    ll nd = q.front();
    q.pop();
    topo.push_back(nd);

    for (ll x : G[nd]) {
      inorder[x]--;

      if (inorder[x] == 0) {
        q.push(x);
      }
    }
  }

  vector<ll> dp(n);
  for (ll i = 0; i < n; ++i) {
    ll nd = topo[i];

    for (ll j : G[nd]) {
      dp[j] = max(dp[j], dp[nd] + 1);
    }
  }

  ll ans = *max_element(all(dp));
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
