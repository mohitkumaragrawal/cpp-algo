#include <bits/stdc++.h>

#include <functional>
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

void solve() {
  ll N;
  cin >> N;

  const ll MAX_MASK = (1 << 20);
  const ll INF = 1e+17;

  vector<vector<ll>> dp(21, vector<ll>(MAX_MASK, -1));

  // O(N^2)
  vector<vector<ll>> C(N, vector<ll>(N));
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) cin >> C[i][j];
  }

  // O(N * 2 ^ N)
  function<ll(ll, ll)> rec = [&](ll i, ll mask) -> ll {
    if (i == -1) {
      if (mask == 0)
        return 0;
      else
        return INF;
    }

    if (dp[i][mask] != -1) return dp[i][mask];

    dp[i][mask] = INF;

    for (int j = 0; j < N; ++j) {
      if (!(mask & (1 << j))) continue;
      ll res = C[i][j] + rec(i - 1, mask ^ (1 << j));

      dp[i][mask] = min(dp[i][mask], res);
    }
    return dp[i][mask];
  };

  ll ans = rec(N - 1, (1 << N) - 1);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

#ifdef _DEBUG
  auto start = chrono::high_resolution_clock::now();
#endif

  ll T = 1;
  while (T--) {
    solve();
  }

#ifdef _DEBUG
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
  auto time_taken = ((double)duration.count()) / 1000.0;
  LOG("time taken = " << time_taken << " ms");
#endif
}
