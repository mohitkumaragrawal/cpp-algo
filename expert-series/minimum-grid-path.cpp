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

ll N;
ll C[200005];

void solve() {
  cin >> N;
  for (ll i = 0; i < N; ++i) cin >> C[i];

  ll a_min = C[0], b_min = C[1];
  ll a_sum = C[0], b_sum = C[1];
  ll a_sz = 1, b_sz = 1;

  ll ans = N * (C[0] + C[1]);

  for (ll i = 2; i < N; ++i) {
    if (i % 2 == 0) {
      a_sz++;
      a_sum += C[i];
      a_min = min(a_min, C[i]);
    } else {
      b_sz++;
      b_sum += C[i];
      b_min = min(b_min, C[i]);
    }

    ll tmp = (a_sum - a_min) + a_min * (N - a_sz + 1);
    tmp += (b_sum - b_min) + b_min * (N - b_sz + 1);

    ans = min(ans, tmp);
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
