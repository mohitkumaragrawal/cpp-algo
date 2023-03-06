#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

using matrix = vector<vector<ll>>;

const ll MOD = 1e9 + 7;

matrix mul(matrix& a, matrix& b, ll n) {
  matrix res(n, vector<ll>(n));
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < n; ++j) {
      for (ll k = 0; k < n; ++k) {
        res[i][j] += a[i][k] * b[k][j];
        res[i][j] %= MOD;
      }
    }
  }
  return res;
}

matrix binexp(matrix& base, ll pow, ll n) {
  matrix res(n, vector<ll>(n));
  for (ll i = 0; i < n; ++i) res[i][i] = 1;

  while (pow > 0) {
    if (pow & 1) {
      pow--;
      res = mul(res, base, n);
    }
    pow /= 2;
    base = mul(base, base, n);
  }

  return res;
}

void solve() {
  ll n, k;
  cin >> n >> k;
  matrix a(n, vector<ll>(n));
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < n; ++j) cin >> a[i][j];
  }

  matrix expo = binexp(a, k, n);
  ll res = 0;
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < n; ++j) {
      res = (res + expo[i][j]) % MOD;
    }
  }

  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
