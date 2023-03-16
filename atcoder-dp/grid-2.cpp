#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
ll binexp(ll a, ll b, ll p = MOD) {
  if (b < 0) return 0;
  ll res = 1;
  while (b > 0) {
    if (b & 1) b--, res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res;
}

inline ll modinv(ll x, ll p = MOD) { return binexp(x, p - 2, p); }
template <ll mod>
struct MODINT_ {
  ll value;
  MODINT_() = default;
  MODINT_(ll x) : value(x % mod) {}
  MODINT_(const MODINT_& m) : value(m.value % mod) {}
  MODINT_& operator=(const MODINT_& m) {
    value = m.value;
    return *this;
  }
  ll inverse_value() const { return modinv(value, mod); }
  MODINT_& operator+=(const MODINT_& m) {
    value = (value + m.value) % mod;
    return *this;
  }
  MODINT_& operator-=(const MODINT_& m) {
    value = (mod + value - m.value) % mod;
    return *this;
  }
  MODINT_& operator*=(const MODINT_& m) {
    value = (value * m.value) % mod;
    return *this;
  }
  MODINT_& operator/=(const MODINT_& m) {
    value = (value * m.inverse_value()) % mod;
    return *this;
  }
  MODINT_& operator++() {
    value++;
    value %= mod;
    return *this;
  }
  MODINT_& operator--() {
    value--;
    value %= mod;
    return *this;
  }
  MODINT_ operator*(const MODINT_& b) { return MODINT_(value * b.value); }
  MODINT_ operator*(ll b) { return MODINT_(value * b); }
  MODINT_ operator-(const MODINT_& b) { return MODINT_(mod + value - b.value); }
  MODINT_ operator-(ll b) { return MODINT_(mod + value - b); }
  MODINT_ operator+(const MODINT_& b) { return MODINT_(value + b.value); }
  MODINT_ operator+(ll b) { return MODINT_(value + b); }
  MODINT_ operator/(const MODINT_& b) {
    return MODINT_(value * modinv(b.value, mod));
  }
  MODINT_ operator/(ll b) { return MODINT_(value * modinv(b, mod)); }
};
template <ll mod>
ostream& operator<<(ostream& out, const MODINT_<mod>& m) {
  out << m.value % mod;
  return out;
}
template <ll mod>
istream& operator>>(istream& in, MODINT_<mod>& m) {
  ll x;
  in >> x;
  m.value = (x % mod);
  return in;
}
using MODINT = MODINT_<MOD>;

vector<MODINT> factorial;
vector<MODINT> inv_factorial;

void init_factorial() {
  factorial.resize(1000005);
  factorial[0] = factorial[1] = 1;
  for (ll i = 2; i < 1000005; ++i) {
    factorial[i] = (factorial[i - 1] * i);
  }

  inv_factorial.resize(1000005);
  inv_factorial[1000004] = MODINT(1) / factorial[1000004];
  for (ll i = 1000003; i >= 0; --i) {
    inv_factorial[i] = inv_factorial[i + 1] * (i + 1);
  }
}

void solve() {
  ll h, w, n;
  cin >> h >> w >> n;

  // returns the number of ways to go from (xi, yi) to (xf, yf) such that there
  // are no blocks
  auto f = [](ll xi, ll yi, ll xf, ll yf) {
    ll dx = xf - xi;
    ll dy = yf - yi;
    return factorial[dx + dy] * inv_factorial[dx] * inv_factorial[dy];
  };

  vector<pair<ll, ll>> points(n);
  for (auto& [x, y] : points) {
    cin >> x >> y;
  }
  points.push_back({h, w});
  sort(all(points));
  n++;

  MODINT dp[n];

  for (ll i = 0; i < n; ++i) dp[i] = f(1, 1, points[i].first, points[i].second);

  for (ll i = 1; i < n; ++i) {
    for (ll j = 0; j < i; ++j) {
      if (points[j].first <= points[i].first &&
          points[j].second <= points[i].second) {
        dp[i] -= dp[j] * f(points[j].first, points[j].second, points[i].first,
                           points[i].second);
      }
    }
  }

  cout << dp[n - 1] << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  init_factorial();

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
