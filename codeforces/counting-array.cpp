#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll MOD = 998244353LL;


bool sieve[300'005];
ll a[300'0005];
ll p[300'0005];

void init_sieve() {
  for (ll i = 0; i <= 300000; ++i)
    sieve[i] = true;
  sieve[0] = sieve[1] = false;
  for (ll i = 2; i * i <= 300'000; ++i) {
    if (!sieve[i])
      continue;
    for (ll j = i * i; j <= 300'000; j += i) {
      sieve[j] = false;
    }
  }
}

ll bin_exp(ll base, ll pow) {
  ll res = 1;
  while (pow >= 1) {
    if (pow & 1) {
      pow--;
      res = (res * base) % MOD;
    } else {
      pow /= 2;
      base = (base * base) % MOD;
    }
  }
  return res;
}

void solve() {
  init_sieve();

  ll n, m;
  cin >> n >> m;

  ll ans = 0;
  for (ll i = 1; i <= n; ++i) {
    ans = (ans + bin_exp((m % MOD), i)) % MOD;
  }

  ll curr = 1;
  ll cnt = 1;
  for (ll i = 1; i <= n; ++i) {
    if (curr > m)
      continue;
    if (sieve[i]) {
      curr *= i;
    }

    cnt = (cnt * ((m / curr) % MOD)) % MOD;

    ans -= cnt;
    if (ans < 0)
      ans += MOD;
  }
  cout << ans << endl;
}

int main() {

  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}
