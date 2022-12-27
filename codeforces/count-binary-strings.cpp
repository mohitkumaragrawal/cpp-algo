#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

const ll MOD = 998244353;

ll dp[105][105], R[105][105];

void solve() {
  ll n;
  cin >> n;

  bool invalid = false;
  for (ll i = 1; i <= n; ++i) {
    for (ll j = i; j <= n; ++j) {
      cin >> R[i][j];

      if (j == i && R[i][j] == 2) {
        invalid = true;
      }
    }
  }
  if (invalid) {
    cout << 0 << endl;
    return;
  }

  dp[1][0] = 2;
  for (ll i = 2; i <= n; ++i) {
    for (ll j = 0; j < i; ++j) {
      bool valid = true;
      for (ll k = 1; k < i; ++k) {
        if (R[k][i] == 2) {
          if (j < k) {
            valid = false;
            break;
          }
        } else if (R[k][i] == 1) {
          if (j >= k) {
            valid = false;
            break;
          }
        }
      }

      if (valid) {
        if (j != i - 1) {
          dp[i][j] = dp[i - 1][j];
        } else {
          for (ll k = 0; k < j; ++k) {
            dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
          }
        }
      } else {
        dp[i][j] = 0;
      }
    }
  }

  ll ans = 0;
  for (ll j = 0; j < n; ++j) ans = (ans + dp[n][j]) % MOD;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}
