#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using ull = unsigned long long;

ll pow10[19];
void precomputation() {
  pow10[0] = 1;
  for (ll i = 1; i < 19; ++i) pow10[i] = 10 * pow10[i - 1];
}

// counts the number upto 1..X, such that they starts with 1;
ll calculate_ones(ll x) {
  if (x == 0) return 0;
  ll digit_count = 0;
  ll tmp = x;
  bool flag = false;
  while (tmp > 0) {
    digit_count++;
    if (tmp / 10 == 0) {
      flag = (tmp == 1);
    }
    tmp /= 10;
  }
  ll ans = 0;
  for (ll i = 0; i < digit_count - 1; ++i) {
    ans += pow10[i];
  }
  if (!flag) {
    ans += pow10[digit_count - 1];
  } else {
    x -= pow10[digit_count - 1];
    ans += x + 1;
  }
  return ans;
}

lld p[1005], dp[1005][1005];

void solve() {
  ll n;
  cin >> n;

  for (ll i = 0; i < n; ++i) {
    ll l, r;
    cin >> l >> r;

    ll ones = calculate_ones(r) - calculate_ones(l - 1);
    p[i] = ((lld)ones) / ((lld)(r - l + 1));
  }

  ll k;
  cin >> k;

  memset(dp, 0, sizeof(dp));
  dp[0][0] = (1 - p[0]);
  dp[0][1] = p[0];

  for (ll i = 0; i < n - 1; ++i) {
    for (ll j = 0; j <= n; ++j) {
      dp[i + 1][j + 1] += p[i + 1] * dp[i][j];
      dp[i + 1][j] += (1 - p[i + 1]) * dp[i][j];
    }
  }

  ll m = ((n * k) + 99) / 100;
  lld ans = 0;
  for (ll i = m; i <= n; ++i) {
    ans += dp[n - 1][i];
  }

  cout << setprecision(12) << fixed << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  precomputation();

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
