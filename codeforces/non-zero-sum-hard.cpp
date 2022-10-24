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
#define DEBUG4(x, y, z, w) display << _MC_(x) << _MC_(y) << _MC_(z) << _MC_(w) << endl;
#else
#define display cout
#define LOG(x)
#define DEBUG(x)
#define DEBUG2(x, y)
#define DEBUG3(x, y, z)
#define DEBUG4(x, y, z, w)
#endif

ll arr[200'005];

void solve() {
  ll n; cin >> n;

  ll zero_cnt = 0;
  
  for (ll i = 1; i <= n; ++i) {
    cin >> arr[i];
    if (i % 2 == 0) arr[i] = -arr[i];

    if (arr[i] == 0) zero_cnt ++;
  }

  if ((n - zero_cnt) % 2 != 0) {
    cout << -1 << endl;
    return;
  }

  if (zero_cnt == n) {
    cout << 1 << endl;
    cout << 1 << " " << n << endl;
    return;
  }

  vector<pair<ll, ll>> ans;

  auto next_non_zero = [&](ll off) -> ll {
    for (ll i = off; i <= n; ++i) {
      if (arr[i] != 0) return i;
    } 
    return -1;
  };

  ll pl = next_non_zero(1);
  ll pr = next_non_zero(pl+1);

  if (pl != 1) {
    ans.push_back({1, pl-1});
  }

  if (arr[pl] == arr[pr]) {
    ans.push_back({pl, pl});
    ans.push_back({pl+1, pr});
  } else {
    ans.push_back({pl, pr});
  }

  while (true) {
    ll l = next_non_zero(pr+1);
    if (l == -1) break;

    ll r = next_non_zero(l+1);

    if (l != pr+1) {
      ans.push_back({pr + 1, l - 1});
    }

    if (arr[l] == arr[r]) {
      ans.push_back({l, l});
      ans.push_back({l + 1, r});
    } else {
      ans.push_back({l, r});
    }

    pl = l, pr = r;
  }

  if (pr != n) {
    ans.push_back({pr+1, n});
  }

  cout << ans.size() << endl;
  for (auto pr: ans) {
    cout << pr.first << " " << pr.second << endl;
  }
}


int main() { 
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;

  while (T--) solve();
}
