#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll MOD = 1e9 + 7;

// In debug mode show some additional information;
#define endl '\n'
#ifdef _DEBUG
#define display cout << "\033[1;31m* (" << __LINE__ << "):\033[0m "
#define LOG(x) display << x << endl
#define _MC_(x) #x "=" << x << "\t"
#define DEBUG(x) display << _MC_(x) << endl
#define DEBUG2(x, y) display << _MC_(x) << _MC_(y) << endl
#define DEBUG3(x, y, z) display << _MC_(x) << _MC_(y) << _MC_(z) << endl
#define DEBUG4(x, y, z, w)                                                     \
  display << _MC_(x) << _MC_(y) << _MC_(z) << _MC_(w) << endl;
#else
#define display cout
#define LOG(x)
#define DEBUG(x)
#define DEBUG2(x, y)
#define DEBUG3(x, y, z)
#define DEBUG4(x, y, z, w)
#endif

ll arr[200005];

void solve() {
  ll n;
  cin >> n;

  for (ll i = 1; i <= n; ++i) {
    cin >> arr[i];
    if (i % 2 == 0) {
      arr[i] = -arr[i];
    }
  }

  if (n % 2 == 1) {
    cout << -1 << endl;
    return;
  }

  vector<pair<ll, ll>> ans;
  for (ll i = 1; i < n; i+=2) {
    ll a = arr[i], b = arr[i + 1];
    if (a != b) {
      ans.push_back({i, i + 1});
      continue;
    }
    ans.push_back({i, i});
    ans.push_back({i + 1, i + 1});
  }

  cout << ans.size() << endl;
  for (auto pr: ans) {
    display << pr.first << " " << pr.second << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--)
    solve();
}
