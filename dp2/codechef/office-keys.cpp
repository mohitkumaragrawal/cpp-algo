#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  ll N;
  cin >> N;
  vector<ll> p(N);
  for (ll& i : p) cin >> i;

  ll M;
  cin >> M;
  vector<ll> k(M);
  for (ll& i : k) cin >> i;

  ll X;
  cin >> X;

  sort(p.begin(), p.end());
  sort(k.begin(), k.end());

  ll inf = 1e+17;
  vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, inf));
  dp[0][0] = 0;

  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < M; ++j) {
      dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);

      ll cost = abs(p[i] - k[j]) + abs(k[j] - X);
      dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], cost));
    }
  }
  ll ans = *min_element(dp[N].begin(), dp[N].end());
  cout << ans << endl;
}