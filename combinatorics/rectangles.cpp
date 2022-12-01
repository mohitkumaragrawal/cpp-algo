#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll arr[55][55], pre[55][55];
ll pow2[200];

#ifndef _DEBUG
#define endl '\n'
#endif

void solve() {
  ll m, n;
  cin >> m >> n;

  pow2[0] = 1;
  for (ll i = 1; i < 63; ++i) pow2[i] = 2 * pow2[i - 1];

  for (ll i = 1; i <= m; ++i) {
    for (ll j = 1; j <= n; ++j) {
      cin >> arr[i][j];
    }
  }

  for (ll i = 1; i <= m; ++i) {
    for (ll j = 1; j <= n; ++j) {
      pre[i][j] = arr[i][j] + pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
    }
  }

  auto count_colored = [&](ll r, ll c) -> pair<ll, ll> {
    ll l1 = (pre[m][c] - pre[m][c - 1]) - (pre[r - 1][c] - pre[r - 1][c - 1]);
    ll l2 = (pre[r][n] - pre[r - 1][n]) - (pre[r][c - 1] - pre[r - 1][c - 1]);

    return {l1, l2};
  };

  auto count_uncolored = [&](ll r, ll c) -> pair<ll, ll> {
    auto [x, y] = count_colored(r, c);
    return make_pair<ll, ll>((m - r + 1) - x, (n - c + 1) - y);
  };

  ll ans = 0;

  for (ll i = 1; i <= m; ++i) {
    for (ll j = 1; j <= n; ++j) {
      pair<ll, ll> similar;
      if (arr[i][j] == 0) {
        similar = count_uncolored(i, j);
      } else {
        similar = count_colored(i, j);
      }
      auto [x, y] = similar;
      ans += 1 + (pow2[x - 1] - 1) + (pow2[y - 1] - 1);
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}
