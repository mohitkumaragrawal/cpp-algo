#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll n;
vector<vector<ll>> G;
ll s[100005];
const ll INF = 1e+17;

ll dfs(ll node, ll parent_sum) {
  if (s[node] != -1 && parent_sum > s[node]) {
    return -1;
  }
  if (s[node] == -1) {
    s[node] = INF;
    for (ll child : G[node]) {
      s[node] = min(s[node], s[child]);
    }
    if (s[node] == INF) s[node] = parent_sum;
    if (s[node] < parent_sum) return -1;
  }

  ll ans = s[node] - parent_sum;
  for (ll child : G[node]) {
    ll y = dfs(child, s[node]);
    if (y == -1) {
      return -1;
    }
    ans += y;
  }
  return ans;
}

void solve() {
  cin >> n;
  G.resize(n);
  for (ll i = 1; i < n; ++i) {
    ll p;
    cin >> p;
    p--;
    G[p].push_back(i);
  }

  for (ll i = 0; i < n; ++i) cin >> s[i];
  cout << dfs(0, 0) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
