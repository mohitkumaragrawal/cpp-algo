#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll a[100005], f[100005], g[100005], c[100005];
constexpr ll mx = 100000;

/**
 * a[i] = elements of array;
 * f[i] = # of sequences whose gcd = i;
 * g[i] = # of sequences whose gcd is a multiple of i;
 *
 * f[i] = g[i] - ( f[2i] + f[3i] + f[4i] + ... );
 *
 * Ans = f[1]
 */

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

void solve() {
  ll n;
  cin >> n;

  memset(c, 0, sizeof(c));
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
    c[a[i]]++;
  }

  for (ll i = 1; i <= mx; ++i) {
    ll cnt = 0;
    for (ll j = i; j <= mx; j += i) {
      cnt += c[j];
    }
    g[i] = (MOD + binexp(2, cnt) - 1) % MOD;
  }

  for (ll i = mx; i >= 1; --i) {
    f[i] = g[i];
    for (ll j = 2 * i; j <= mx; j += i) {
      f[i] = (MOD + f[i] - f[j]) % MOD;
    }
  }

  cout << f[1] << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
