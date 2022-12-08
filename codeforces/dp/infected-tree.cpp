#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll N;
vector<vector<ll>> G;
ll PARENT[300005], DEPTH[300005], SIZE[300005], DP[300005];

void DFS(ll n, ll p) {
  PARENT[n] = p;
  SIZE[n] = 1;

  for (ll child : G[n]) {
    if (child == p) continue;

    DEPTH[child] = 1 + DEPTH[n];

    DFS(child, n);
    SIZE[n] += SIZE[child];
  }
}

ll infect(ll nd) {
  if (DEPTH[nd] > N) return DP[nd] = SIZE[nd];
  if (DP[nd] != -1) return DP[nd];

  vector<ll> CHILD;

  for (ll child : G[nd]) {
    if (child != PARENT[nd]) CHILD.push_back(child);
  }

  if (CHILD.size() == 0) {
    return 0;
  }
  if (CHILD.size() == 1) {
    ll c = CHILD[0];
    if (DEPTH[c] > N) return SIZE[c];
    return DP[nd] = SIZE[c] - 1;
  }

  ll c1 = CHILD[0], c2 = CHILD[1];

  if (DEPTH[nd] == N) {
    return DP[nd] = SIZE[c1] + SIZE[c2];
  }

  ll ans1 = SIZE[c1] - 1 + infect(c2);
  ll ans2 = SIZE[c2] - 1 + infect(c1);

  return DP[nd] = max(ans1, ans2);
}

void solve() {
  G.clear();
  cin >> N;

  G.resize(N);

  for (ll i = 0; i < N - 1; ++i) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;

    G[x].push_back(y);
    G[y].push_back(x);
  }

  DEPTH[0] = 0;
  DFS(0, -1);

  // for (ll i = 0; i < N; ++i) DP[i] = -1;
  fill(DP, DP + N, -1);

  ll ans = infect(0);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
