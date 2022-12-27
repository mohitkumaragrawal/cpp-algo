#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

// dp[i][j] = no. of ways to create a bitonic subarray (i, j) such that the
// range of the elements in it [n, n - length], where length = j - i + 1
// so the transition is, say if we are at state (i, j) meaning the elements in
// it are of the range [n, n - (j - i + 1)], we extend the length of it like i
// -> i-1 or j -> j + 1; and if we can fill (n - length - 1) in those places we
// add dp[i][j] to the new state;

ll dp[105][105];
ll n, pi, pj, vi, vj;

bool is_valid(ll p, ll v) {
  if (p == pi && v != vi) return false;
  if (p == pj && v != vj) return false;
  return true;
}

void solve() {
  cin >> n >> pi >> pj >> vi >> vj;
  pi--;
  pj--;
  memset(dp, 0, sizeof(dp));

  for (ll i = 1; i < n - 1; ++i) {
    if (is_valid(i, n)) dp[i][i] = 1;
  }

  for (ll length = 1; length < n; ++length) {
    for (ll i = 0; i < n; ++i) {
      ll j = i + length - 1;
      if (j >= n) break;
      ll val = n - length;

      if (i - 1 >= 0 && is_valid(i - 1, val)) {
        dp[i - 1][j] = (dp[i - 1][j] + dp[i][j]) % MOD;
      }

      if (j + 1 < n && is_valid(j + 1, val)) {
        dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
      }
    }
  }

  cout << dp[0][n - 1] << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
