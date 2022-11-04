#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using namespace std;
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

ll x_cords[1001], y_cords[1001];
ll N;

ll valid_range(ll arr[]) {
  if (N % 2 == 0) {
    ll r = N / 2;
    return arr[r] - arr[r - 1] + 1;
  } else {
    return 1;
  }
}

void solve() {
  cin >> N;

  for (ll i = 0; i < N; ++i) {
    cin >> x_cords[i] >> y_cords[i];
  }

  sort(begin(x_cords), begin(x_cords) + N);
  sort(begin(y_cords), begin(y_cords) + N);

  ll ans = valid_range(x_cords) * valid_range(y_cords);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
