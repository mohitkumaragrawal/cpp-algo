#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[1002][1002];
const int sz = 1001;

void solve() {
  int N, Q;
  cin >> N >> Q;

  for (int i = 0; i < sz; ++i) {
    for (int j = 0; j < sz; ++j) {
      dp[i][j] = 0;
    }
  }

  for (int i = 0; i < N; ++i) {
    ll h, w;
    cin >> h >> w;
    dp[h][w] += h * w;
  }
  for (ll i = 1; i < sz; ++i) {
    for (ll j = 1; j < sz; ++j) {
      dp[i][j] += dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
    }
  }

  while (Q--) {
    ll hs, ws, hb, wb;
    cin >> hs >> ws >> hb >> wb;

    ll ans = dp[hb - 1][wb - 1] - dp[hb - 1][ws] - dp[hs][wb - 1] + dp[hs][ws];
    cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) solve();
}