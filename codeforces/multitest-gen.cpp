#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n);

  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<array<ll, 2>> dp(n + 1, array<ll, 2>{-1, -1});
  dp[n][0] = 0;
  ll mx_dp = 0;

  for (ll i = n - 1; i >= 0; --i) {
    ll k = i + a[i] + 1;

    // with changes;
    dp[i][1] = 1 + mx_dp;
    if (k <= n && dp[k][1] != -1) {
      dp[i][1] = max(dp[i][1], 1 + dp[k][1]);
    }

    // with no changes;
    if (k <= n && dp[k][0] != -1) {
      dp[i][0] = 1 + dp[k][0];
      mx_dp = max(mx_dp, dp[i][0]);
    }
  }

  vector<ll> ans(n - 1, 2);
  for (ll i = n - 2; i >= 0; --i) {
    if (a[i] == dp[i + 1][0]) {
      ans[i] = 0;
      continue;
    }

    if (dp[i + 1][0] != -1) {
      ans[i] = 1;
      continue;
    }

    ll mx = dp[i + 1][1];
    if (mx >= a[i]) {
      ans[i] = 1;
      continue;
    }
  }

  for (ll i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
