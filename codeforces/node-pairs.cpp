#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll dp[200005];

inline ll choose2(ll x) { return (x * (x - 1)) / 2; }

void solve() {
  ll p;
  cin >> p;

  fill(dp, dp + p + 1, 1e15);
  dp[0] = 0;
  for (ll i = 1; i <= p; ++i) {
    for (ll j = 2;; ++j) {
      ll y = choose2(j);
      if (y > i) break;

      dp[i] = min(dp[i], j + dp[i - y]);
    }
  }

  ll n = dp[p];
  ll q = choose2(n) - p;
  cout << n << " " << q << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
