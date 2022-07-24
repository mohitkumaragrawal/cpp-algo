#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll v1, v2;
  cin >> v1 >> v2;
  if (v2 < v1) swap(v1, v2);

  ll t, d;
  cin >> t >> d;

  ll max_velocity = v2 + d * t;

  vector<vector<ll>> dp(t, vector<ll>(max_velocity + 1, -1));
  dp[0][0] = 0;

  // for (ll time = 1; time < t; ++time) {
  //   for (ll vel = 0; vel <= max_velocity; ++vel) {
  //     ll max_d = -1;
  //     for (ll pv = vel - d; pv <= vel + d; ++pv) {
  //       if (pv < 0) continue;
  //       if (pv > max_velocity) continue;

  //       max_d = max(max_d, dp[time - 1][pv]);
  //     }
  //     if (max_d == -1) continue;
  //     dp[time][vel] = max_d + vel;
  //   }
  // }

  for (ll time = 0; time < t - 1; ++time) {
    for (ll vel = 0; vel <= max_velocity; ++vel) {
      if (dp[time][vel] == -1) continue;
      for (ll nvel = vel - d; nvel <= vel + d; ++nvel) {
        if (nvel < 0 || nvel > max_velocity) continue;

        dp[time + 1][nvel] = max(dp[time + 1][nvel], nvel + dp[time][vel]);
      }
    }
  }

  cout << dp[t - 1][v2 - v1] + (v1 * t) << endl;
}