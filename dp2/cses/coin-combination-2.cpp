#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll dp[1000001];
ll c[105];
const ll MOD = 1e9 + 7;

void solve() {
  ll n, x;
  cin >> n >> x;
  for (ll i = 0; i < n; ++i) cin >> c[i];

  dp[0] = 1;

  for (ll i = 0; i < n; ++i) {
    ll cn = c[i];

    for (ll j = 0; j < x; ++j) {
      if (j + cn > x) continue;
      dp[j + cn] += dp[j];
      dp[j + cn] %= MOD;
    }
  }

  cout << dp[x] << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}
