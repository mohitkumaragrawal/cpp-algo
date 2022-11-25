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
using ll = long long;
using ull = unsigned long long;

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

ll ans[505][505];
ll pos[505];

void solve() {
  for (ll i = 0; i < 505; ++i) {
    for (ll j = 0; j < 505; ++j) {
      ans[i][j] = -1;
    }
  }
  ll N;
  cin >> N;

  for (ll i = 1; i <= N; ++i) pos[i] = -1;

  for (ll i = 0; i < N; ++i) {
    cin >> ans[i][i];
  }

  for (ll i = 0; i < N; ++i) {
    if (pos[ans[i][i]] != -1) {  // duplicate
      cout << -1 << endl;
      return;
    }
    pos[ans[i][i]] = i;
  }

  // down then right;

  for (ll i = N - 1; i >= 0; --i) {
    ll x = ans[i][i];

    ll row = i, col = i;
    for (ll j = 0; j < x - 1; ++j) {
      // can go down;
      if (row + 1 < N && ans[row + 1][col] == -1) {
        row++;
        ans[row][col] = x;
        continue;
      }

      // should go left;
      col--;
      ans[row][col] = x;
    }
  }

  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j <= i; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
