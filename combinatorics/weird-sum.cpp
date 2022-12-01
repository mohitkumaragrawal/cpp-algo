#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll m, n;
  cin >> m >> n;

  ll arr[m + 1][n + 1];
  for (ll i = 1; i <= m; ++i) {
    for (ll j = 1; j <= n; ++j) {
      cin >> arr[i][j];
    }
  }

  // color: [list of rows/cols in which they exist]
  map<ll, vector<ll>> rows, cols;

  for (ll i = 1; i <= m; ++i) {
    for (ll j = 1; j <= n; ++j) {
      rows[arr[i][j]].push_back(i);
      cols[arr[i][j]].push_back(j);
    }
  }

  for (auto& [clr, vec] : cols) sort(all(vec));

  auto calc_value = [](const vector<ll>& v) -> ll {
    if (v.size() == 0) return 0;

    ll sum = 0;
    ll N = v.size() - 1;
    ll ans = 0;

    for (ll i = N; i >= 0; --i) {
      ans += sum - (N - i) * v[i];
      sum += v[i];
    }
    return ans;
  };

  ll ans = 0;
  for (auto& [_, v] : rows) ans += calc_value(v);
  for (auto& [_, v] : cols) ans += calc_value(v);

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
