#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if< !is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template <const int &MOD>
struct _m_int {
  int val;

  _m_int(int64_t v = 0) {
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    val = int(v);
  }

  _m_int(uint64_t v) {
    if (v >= MOD) v %= MOD;
    val = int(v);
  }

  _m_int(int v) : _m_int(int64_t(v)) {}
  _m_int(unsigned v) : _m_int(uint64_t(v)) {}

  explicit operator int() const { return val; }
  explicit operator unsigned() const { return val; }
  explicit operator int64_t() const { return val; }
  explicit operator uint64_t() const { return val; }
  explicit operator double() const { return val; }
  explicit operator long double() const { return val; }

  _m_int &operator+=(const _m_int &other) {
    val -= MOD - other.val;
    if (val < 0) val += MOD;
    return *this;
  }

  _m_int &operator-=(const _m_int &other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }

  static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
    return unsigned(x % m);
#endif
    // Optimized mod for Codeforces 32-bit machines.
    // x must be less than 2^32 * m for this to work, so that x / m fits in an
    // unsigned 32-bit int.
    unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
    unsigned quot, rem;
    asm("divl %4\n" : "=a"(quot), "=d"(rem) : "d"(x_high), "a"(x_low), "r"(m));
    return rem;
  }

  _m_int &operator*=(const _m_int &other) {
    val = fast_mod(uint64_t(val) * other.val);
    return *this;
  }

  _m_int &operator/=(const _m_int &other) { return *this *= other.inv(); }

  friend _m_int operator+(const _m_int &a, const _m_int &b) {
    return _m_int(a) += b;
  }
  friend _m_int operator-(const _m_int &a, const _m_int &b) {
    return _m_int(a) -= b;
  }
  friend _m_int operator*(const _m_int &a, const _m_int &b) {
    return _m_int(a) *= b;
  }
  friend _m_int operator/(const _m_int &a, const _m_int &b) {
    return _m_int(a) /= b;
  }

  _m_int &operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }

  _m_int &operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }

  _m_int operator++(int) {
    _m_int before = *this;
    ++*this;
    return before;
  }
  _m_int operator--(int) {
    _m_int before = *this;
    --*this;
    return before;
  }

  _m_int operator-() const { return val == 0 ? 0 : MOD - val; }

  friend bool operator==(const _m_int &a, const _m_int &b) {
    return a.val == b.val;
  }
  friend bool operator!=(const _m_int &a, const _m_int &b) {
    return a.val != b.val;
  }
  friend bool operator<(const _m_int &a, const _m_int &b) {
    return a.val < b.val;
  }
  friend bool operator>(const _m_int &a, const _m_int &b) {
    return a.val > b.val;
  }
  friend bool operator<=(const _m_int &a, const _m_int &b) {
    return a.val <= b.val;
  }
  friend bool operator>=(const _m_int &a, const _m_int &b) {
    return a.val >= b.val;
  }

  static const int SAVE_INV = int(1e6) + 5;
  static _m_int save_inv[SAVE_INV];

  static void prepare_save() {
    // Make sure MOD is prime, which is necessary for the inverse algorithm
    // below.
    for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1) assert(MOD % p != 0);

    save_inv[0] = 0;
    save_inv[1] = 1;

    for (int i = 2; i < SAVE_INV; i++)
      save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
  }

  _m_int inv() const {
    if (save_inv[1] == 0) prepare_save();

    if (val < SAVE_INV) return save_inv[val];

    _m_int product = 1;
    int v = val;

    while (v >= SAVE_INV) {
      product *= MOD - MOD / v;
      v = MOD % v;
    }

    return product * save_inv[v];
  }

  _m_int pow(int64_t p) const {
    if (p < 0) return inv().pow(-p);

    _m_int a = *this, result = 1;

    while (p > 0) {
      if (p & 1) result *= a;

      p >>= 1;

      if (p > 0) a *= a;
    }

    return result;
  }

  friend ostream &operator<<(ostream &os, const _m_int &m) {
    return os << m.val;
  }
};

template <const int &MOD>
_m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];

extern const int MOD = int(1e9) + 7;
using mod_int = _m_int<MOD>;

const int BITS = 19;

template <typename T>
struct xor_basis {
  // A list of basis values sorted in decreasing order, where each value has a
  // unique highest bit. We use a static array instead of a vector for better
  // performance.
  T basis[BITS];
  int n = 0;

  T min_value(T start) const {
    if (n == BITS) return 0;

    for (int i = 0; i < n; i++) start = min(start, start ^ basis[i]);

    return start;
  }

  T max_value(T start = 0) const {
    if (n == BITS) return (T(1) << BITS) - 1;

    for (int i = 0; i < n; i++) start = max(start, start ^ basis[i]);

    return start;
  }

  bool add(T x) {
    x = min_value(x);

    if (x == 0) return false;

    basis[n++] = x;

    // Insertion sort.
    for (int k = n - 1; k > 0 && basis[k] > basis[k - 1]; k--)
      swap(basis[k], basis[k - 1]);

    return true;
  }

  void merge(const xor_basis<T> &other) {
    for (int i = 0; i < other.n && n < BITS; i++) add(other.basis[i]);
  }

  void merge(const xor_basis<T> &a, const xor_basis<T> &b) {
    if (a.n > b.n) {
      *this = a;
      merge(b);
    } else {
      *this = b;
      merge(a);
    }
  }
};

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
  maximum = max(maximum, 1);
  smallest_factor.assign(maximum + 1, 0);
  prime.assign(maximum + 1, true);
  prime[0] = prime[1] = false;
  primes = {};

  for (int p = 2; p <= maximum; p++)
    if (prime[p]) {
      smallest_factor[p] = p;
      primes.push_back(p);

      for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
        if (prime[i]) {
          prime[i] = false;
          smallest_factor[i] = p;
        }
    }
}

const int A_MAX = 70;

int main() {
  ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
  cin.tie(nullptr);
#endif

  sieve(A_MAX);
  int P = int(primes.size());
  int N;
  cin >> N;
  xor_basis<int> basis;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    int mask = 0;

    for (int b = 0; b < P; b++) {
      int p = primes[b], e = 0;

      while (a % p == 0) {
        a /= p;
        e++;
      }

      mask |= (e & 1) << b;
    }

    basis.add(mask);
  }

  cout << mod_int(2).pow(N - basis.n) - 1 << '\n';
}
