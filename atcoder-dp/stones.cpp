#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n, k;
  cin >> n >> k;
  ll a[n];
  for (ll i = 0; i < n; ++i) cin >> a[i];

  ll dp[100005][2];
  dp[0][0] = 1;
  dp[0][1] = 0;

  for (ll i = 1; i <= k; ++i) {
    for (ll j = 0; j < 2; ++j) {
      ll other = j ^ 1;

      // pick one number
      dp[i][j] = other;
      for (ll w = 0; w < n; ++w) {
        ll num = a[w];
        if (i < num) continue;

        ll winner = dp[i - num][other];
        if (winner != dp[i][j]) {
          dp[i][j] = j;
          break;
        }
      }
    }
  }

  ll winner = dp[k][0];
  if (winner == 0) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
