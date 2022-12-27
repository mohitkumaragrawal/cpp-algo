#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

const ll MOD = 998244353;
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
using modint = MODINT_<MOD>;

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
  }

  ll g = count(all(a), 0LL);
  ll k = count(a.begin(), a.begin() + g, 0LL);

  modint ans = 0;
  for (ll x = k; x < g; ++x) {
    ans += modint(n * (n - 1)) / (2 * (g - x) * (g - x));
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
