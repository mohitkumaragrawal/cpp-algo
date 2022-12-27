#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll N;
vector<vector<ll>> G;
ll L[200005], R[200005], dp[200005];
ll sum_val[200005];

void dfs(ll node) {
  ll child_sum = 0;
  ll val = 0;
  for (ll child : G[node]) {
    dfs(child);
    val += dp[child];
    child_sum += sum_val[child];
  }

  if (child_sum >= L[node]) {
    dp[node] = val;
    sum_val[node] = min(child_sum, R[node]);
  } else {
    dp[node] = val + 1;
    sum_val[node] = R[node];
  }
}

void solve() {
  cin >> N;

  G.clear();
  G.resize(N);

  fill(dp, dp + N, 0);
  fill(sum_val, sum_val + N, 0);

  for (ll i = 1; i < N; ++i) {
    ll p;
    cin >> p;
    p--;

    G[p].push_back(i);
  }
  for (ll i = 0; i < N; ++i) cin >> L[i] >> R[i];
  dfs(0);
  cout << dp[0] << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
