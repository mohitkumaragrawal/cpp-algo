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
const ll MOD = 1e9 + 7;

#ifdef _DEBUG
#define __dis cout << "\033[1;31m* (" << __LINE__ << "):\033[0m "
#define LOG(x) __dis << x << endl
#define __m(x) #x "=" << x << "\t"
#define DEBUG(x) __dis << __m(x) << endl
#define DEBUG2(x, y) __dis << __m(x) << __m(y) << endl
#define DEBUG3(x, y, z) __dis << __m(x) << __m(y) << __m(z) << endl
#define DEBUG4(x, y, z, w) \
  __dis << __m(x) << __m(y) << __m(z) << __m(w) << endl;
#else
#define endl '\n'
#define LOG(x)
#define DEBUG(x)
#define DEBUG2(x, y)
#define DEBUG3(x, y, z)
#define DEBUG4(x, y, z, w)
#endif

ll N;
ll fact[200005];

void solve() {
  cin >> N;
  map<ll, ll> freq;

  ll val = -1;

  for (ll i = 0; i < N; ++i) {
    ll x;
    cin >> x;
    freq[x]++;

    if (val == -1) val = x;
    val &= x;
  }

  DEBUG(val);

  ll ans = ((freq[val] * (freq[val] - 1)) % MOD * fact[N - 2]) % MOD;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  fact[0] = 1;
  for (ll i = 1; i < 200005; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }

  ll T;
  cin >> T;
  LOG("testcases " << T);
  while (T--) {
    solve();
  }
}
