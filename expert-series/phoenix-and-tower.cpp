#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll MOD = 1e9 + 7;

// In debug mode show some additional information;
#ifdef _DEBUG
#define __dis cout << "\033[1;31m* (" << __LINE__ << "):\033[0m "
#define LOG(x) __dis << x << endl
#define __m(x) #x "=" << x << "\t"
#define DEBUG(x) __dis << __m(x) << endl
#define DEBUG2(x, y) __dis << __m(x) << __m(y) << endl
#define DEBUG3(x, y, z) __dis << __m(x) << __m(y) << __m(z) << endl
#define DEBUG4(x, y, z, w)                                                     \
  __dis << __m(x) << __m(y) << __m(z) << __m(w) << endl;
#else
#define endl '\n'
#define LOG(x)
#define DEBUG(x)
#define DEBUG2(x, y)
#define DEBUG3(x, y, z)
#define DEBUG4(x, y, z, w)
#endif

ll arr[100'005], y[100'005];

void solve() {
  ll n, m, x;
  cin >> n >> m >> x;

  for (ll i = 0; i < n; ++i) cin >> arr[i];

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> hp;
  for (ll i = 0; i < m; ++i) hp.push({0, i});

  ll max_val = 0;
  for (ll i = 0; i < n; ++i) {
    auto min_pr = hp.top();
    hp.pop();

    ll new_height = min_pr.first + arr[i];
    max_val = max(max_val, new_height);

    y[i] = min_pr.second + 1;
    hp.push({ new_height, min_pr.second });
  }

  if (max_val - hp.top().first > x) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  for (ll i = 0; i < n; ++i) cout << y[i] << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  
  ll T;
  cin >> T;

  while (T--) {
    solve();
  }
}
  
