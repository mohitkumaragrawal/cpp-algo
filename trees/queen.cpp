#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll c[100005];

void solve() {
  ll n;
  cin >> n;

  vector<vector<ll>> children;
  children.resize(n);

  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x >> c[i];
    if (x != -1) {
      x--;
      children[x].push_back(i);
    }
  }

  vector<ll> ans;
  for (ll i = 0; i < n; ++i) {
    if (c[i] == 0) continue;

    ll possible = 1;
    for (ll child : children[i]) possible &= c[child];

    if (possible) ans.push_back(i + 1);
  }
  if (ans.size() == 0) {
    cout << "-1\n";
    return;
  }
  for (ll i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i == n - 1];
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
