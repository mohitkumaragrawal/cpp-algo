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

void solve() {
  ll N;
  cin >> N;

  deque<pair<ll, ll>> prod;
  for (ll i = 0; i < N; ++i) {
    ll a, b;
    cin >> a >> b;
    prod.push_back({b, a});
  }

  sort(prod.begin(), prod.end());
  ll ans = 0;
  ll cnt = 0;

  while (!prod.empty()) {
    ll dis_req = prod[0].first - cnt;

    while (!prod.empty() && dis_req > 0) {
      if (prod.back().second > dis_req) {
        ans += dis_req * 2;
        cnt += dis_req;
        prod.back().second -= dis_req;
        dis_req = 0;
      } else {
        ans += prod.back().second * 2;
        cnt += prod.back().second;
        dis_req -= prod.back().second;
        prod.pop_back();
      }
    }

    if (prod.empty()) break;
    ans += prod[0].second;
    cnt += prod[0].second;
    prod.pop_front();
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
