#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
const ll INF = 1e+10;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int n, x;
  cin >> n >> x;

  vector<int> arr(n);
  for (int& i : arr) cin >> i;

  vector<ll> dp(x + 1, INF);
  dp[0] = 0;

  for (ll i = 0; i < x; ++i) {
    for (int y : arr) {
      if (i + y > x) continue;
      dp[i + y] = min(dp[i + y], 1 + dp[i]);
    }
  }

  if (dp[x] == INF)
    cout << -1 << endl;
  else
    cout << dp[x] << endl;
}