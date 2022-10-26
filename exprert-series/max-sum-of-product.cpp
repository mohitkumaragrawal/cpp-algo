#include <bits/stdc++.h>
using namespace std;

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

ll a[5005], b[5005], rev_sum[5005][5005], pre[5005];

void solve() {
  ll n;
  cin >> n;

  for (ll i = 0; i < n; ++i) cin >> a[i];
  for (ll i = 0; i < n; ++i) cin >> b[i];

  pre[0] = a[0] * b[0];
  for (ll i = 1; i < n; ++i) {
    pre[i] = a[i] * b[i] + pre[i - 1];
  }
  pre[n] = 0;

  for (ll i = 0; i < n; ++i) {
    rev_sum[i][0] = 0;
    rev_sum[i][1] = a[i] * b[i];
  }

  for (ll j = 2; j <= n; ++j) {
    for (ll i = 0; (i + j - 1) < n; ++i) {
      ll k = i + j - 1;
      rev_sum[i][j] = a[i] * b[k] + a[k] * b[i] + rev_sum[i + 1][j - 2];
    }
  }

  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    for (ll j = i; j < n; ++j) {
      ll new_ans = rev_sum[i][j - i + 1] + pre[n - 1] - pre[j];
      if (i > 0) new_ans += pre[i - 1];

      DEBUG(new_ans);
      ans = max(ans, new_ans);
    }
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

#ifdef _DEBUG
  auto start = chrono::high_resolution_clock::now();
#endif

  solve();

#ifdef _DEBUG
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
  auto time_taken = ((double)duration.count()) / 1000.0;
  LOG("time taken = " << time_taken << " ms");
#endif
}
