#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n, a[100], pre[100];

void solve() {
  vector<pll> vpr;
  vector<tuple<ll, ll>> vtp;

  vpr.push_back({2, 3});
  vpr.push_back({2, 4});
  vpr.push_back({2, 1});
  vpr.push_back({1, 1});
  vpr.push_back({1, 3});
  vpr.push_back({3, 3});

  for (auto [x, y] : vpr) {
    vtp.push_back({x, y});
  }

  sort(all(vpr));
  sort(all(vtp));

  for (auto [x, y] : vpr) {
    cout << x << " " << y << '\n';
  }
  cout << endl;
  for (auto [x, y] : vtp) {
    cout << x << " " << y << '\n';
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
