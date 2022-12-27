#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

// dp[i] = max length of subsequence where ith is the last
// element used;
//
// ans = max dp[i]
//
// a[b[p]] ^ b[p+1] < a[b[p+1]] ^ b[p];
//
// j < i;
// b[p] = j;
// b[p+1] = i;
//
// if (a[j] ^ i < a[i] ^ j) {
//    dp[i] = max(dp[i], dp[j] + 1);
// }
//
// a[x] = [0, 200], -> 8 bits; a[x] ^ N = [N - 200, N + 256]
//
// a[j] ^ i -> [i - 200, i + 200]
// a[i] ^ j -> [j - 200, j + 200]
// j < i;
//
// [i - 200, i + 200] < [j - 200, j + 200];
// i - 200 < j + 200;
// j > i - 400;

ll a[300005], dp[300005];

void solve() {
  ll n;
  cin >> n;

  for (ll i = 0; i < n; ++i) cin >> a[i];

  dp[0] = 1;
  for (ll i = 0; i < n; ++i) {
    dp[i] = 1;
    for (ll j = max(0LL, i - 400); j < i; ++j) {
      if ((a[j] ^ i) < (a[i] ^ j)) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  ll ans = *max_element(dp, dp + n);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
