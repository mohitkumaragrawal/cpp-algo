#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n, a[200005], idx[200005];

void solve() {
  cin >> n;
  for (ll i = 0; i < n; ++i) cin >> a[i];

  for (ll i = 0; i < n; ++i) {
    idx[a[i]] = i;
  }

  ll ans = 0;
  bool flag = false;

  for (ll a = n / 2; a >= 1; --a) {
    if (flag) {
      ++ans;
      continue;
    }

    ll b = n + 1 - a;

    bool op_req = idx[b] < idx[a];

    ll a1 = a + 1, b1 = b - 1;
    if (!(idx[a1] >= idx[a] && idx[b1] <= idx[b])) {
      op_req = true;
    }

    if (op_req) {
      flag = true;
      ans++;
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
