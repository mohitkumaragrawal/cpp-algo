#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll a[200005], n;

void solve() {
  cin >> n;
  for (ll i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  a[n] = 1e10;

  ll ans = 0;

  if (a[0] > 0) ++ans;
  for (ll i = 0; i < n; ++i) {
    if (a[i] <= i && a[i + 1] > (i + 1)) ++ans;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
