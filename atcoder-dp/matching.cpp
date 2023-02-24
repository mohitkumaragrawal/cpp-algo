// dp[bitmask]: represents the number of ways to take bitmask womens by __popcount mens;
// ans = dp[1 << (n+1)  - 1]

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD=1e9 +7;

ll dp[1 << 21], n, c[21][21];

ll count_ways(ll mask) {
    if (dp[mask] != -1) return dp[mask];

    ll ways = 0;
    ll cnt = __builtin_popcountll(mask);

    for (ll j = 0; j < 21; ++j) {
        if (!(mask >> j & 1)) continue;

        if ()
    }
}

void solve() {
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;

    cin >> n;

    for (ll i = 0; i < n; ++i){
        for (ll j = 0; j < n; ++j) cin >> c[i][j];
    }


}

int main() {
    solve();
}
