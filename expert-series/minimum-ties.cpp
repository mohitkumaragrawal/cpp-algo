#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T, typename ComparatorFn = less<T>>
// using ordered_set = tree<T, null_type, ComparatorFn, rb_tree_tag,
//                          tree_order_statistics_node_update>;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll MOD = 1e9 + 7;

#ifdef _DEBUG
#define __dis cout << "\033[1;31m* (" << __LINE__ << "):\033[0m "
#define LOG(x) __dis << x << endl
#define __m(x) #x "=" << x << "\t"
#define DEBUG(x) __dis << __m(x) << endl
#define DEBUG2(x, y) __dis << __m(x) << __m(y) << endl
#define DEBUG3(x, y, z) __dis << __m(x) << __m(y) << __m(z) << endl
#define DEBUG4(x, y, z, w) __dis << __m(x) << __m(y) << __m(z) << __m(w) << end
#else
#define endl '\n'
#define LOG(X)
#define DEBUG(X)
#define DEBUG2(x, y)
#define DEBUG3(x, y, z)
#define DEBUG4(x, y, z, w)
#endif

ll dp[101][101][101];

void solve() {
  ll N;
  cin >> N;

  for (ll i = 1; i <= N; ++i) {
    for (ll j = i + 1; j <= N; ++j) {
      cout << dp[N][i][j] << " ";
    }
  }
  cout << endl;
}

void init_dp() {
  for (ll i = 3; i < 101; i += 2) {
    dp[i][i - 1][i] = -1;
    ll prev = i - 2;

    for (ll j = 1; j <= prev; ++j) {
      for (ll k = j + 1; k <= prev; ++k) {
        dp[i][j][k] = dp[prev][j][k];
      }
    }

    for (ll j = 1; j <= prev; ++j) {
      if (j & 1) {
        // (i - 1) beats j
        dp[i][j][i - 1] = -1;
        dp[i][j][i] = 1;
      } else {
        // j beats (i - 1);
        dp[i][j][i - 1] = 1;
        dp[i][j][i] = -1;
      }
    }
  }

  for (ll i = 2; i < 101; i += 2) {
    ll prev = i - 2;

    for (ll j = 1; j <= prev; ++j) {
      for (ll k = j + 1; k <= prev; ++k) {
        dp[i][j][k] = dp[prev][j][k];
      }
    }

    dp[i][i - 1][i] = 0;
    for (ll j = 1; j <= prev; ++j) {
      if (j & 1) {
        dp[i][j][i - 1] = -1;
        dp[i][j][i] = 1;
      } else {
        dp[i][j][i - 1] = 1;
        dp[i][j][i] = -1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  init_dp();

  ll T;
  cin >> T;
  while (T--) solve();
}
