#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll F[1000005], op_cnt[1000005];
ll n, m;

ll choose2(ll x) { return (x * (x - 1)) / 2; }

void compute() {
  // fill(op_cnt, op_cnt + n + 10, 0);
  // fill(F, F + n + 10, 0);

  memset(op_cnt, 0, (n + 10) * sizeof(ll));
  memset(F, 0, (n + 10) * sizeof(ll));

  ll mx = n / 2;
  F[mx] = 1;

  for (ll i = mx - 1; i >= 2; --i) {
    F[i] = choose2(n / i);

    for (ll j = 2 * i; j <= mx; j += i) {
      F[i] -= F[j];
    }
  }

  for (ll i = 2; i <= mx; ++i) {
    op_cnt[i - 1] = F[i] / (i - 1);
  }
}

void solve() {
  cin >> n >> m;
  compute();

  ll ans = 0;
  ll op = n / 2;

  while (m > 0 && op > 0) {
    if (op_cnt[op] == 0) {
      op--;
      continue;
    }

    ll t = min(m / op, op_cnt[op]);
    m -= t * op;
    ans += t * (op + 1);

    op--;
  }

  if (m > 0) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
