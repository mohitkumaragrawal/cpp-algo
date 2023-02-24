#include <bits/stdc++.h>
using namespace std;

using ll = long long;


ll dp[404][404];

const ll INF=1e17;

void solve() {
    ll n;
    cin >> n;
    ll a[n], pre[n];

    for (ll i = 0; i < n; ++i) cin >> a[i];

    pre[0] = a[0];
    for (ll i = 1; i < n; ++i) pre[i] = pre[i-1] + a[i];

    for (ll i = 0; i < n-1; ++i) {
        dp[i][2] = a[i] + a[i+1];
    }

    auto range_sum = [&](ll l, ll r) {
        ll ans = pre[r];
        if (l > 0) ans -= pre[l-1];
        return ans;
    };


    for (ll L = 3; L <= n; ++L) {
        for (ll i = 0; i < n; ++i) {
            dp[i][L] = INF;

            ll j = i + L - 1;
            if (j >= n) break;

            for (ll k = i; k < j; ++k) {
                ll len = k - i + 1;
                ll cost = dp[i][len] + dp[k+1][L-len];

                cost += range_sum(i, k) + range_sum(k+1, j);

                dp[i][L] = min(dp[i][L], cost);
            }
        }
    }

    ll ans = dp[0][n];
    cout << ans << endl;
}

int main() {
    solve();
}