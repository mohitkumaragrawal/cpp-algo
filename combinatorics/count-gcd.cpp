#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

struct sieve_t {
  sieve_t(int n, bool gen_primes = false, bool gen_sieve = false) {
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
      for (int j = i * i; j <= n; j += i) is_prime[j] = false;
    }
    if (gen_primes) {
      for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) primes.push_back(i);
      }
    }
    if (gen_sieve) {
      sieve.assign(n + 1, -1);
      for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
          sieve[i] = i;
          if ((ll)i * i <= n) {
            for (int j = i * i; j <= n; j += i) {
              if (sieve[j] == -1) sieve[j] = i;
            }
          }
        }
      }
    }
  }
  // requires gen_fact; works only upto sz;
  vector<int> fast_factorize(int k) {
    vector<int> res;
    while (k > 1) {
      ll p = sieve[k];
      res.push_back(p);
      k /= p;
    }
    return res;
  }
  // requies gen_primes; works upto sz*sz;
  vector<int> factorize(int k) {
    vector<int> res;
    for (int p : primes) {
      if (p * p > k) break;
      while (k % p == 0) {
        k /= p;
        res.push_back(p);
      }
    }
    if (k > 1) res.push_back(k);
    return res;
  }
  vector<bool> is_prime;
  vector<int> primes;
  vector<int> sieve;
};

sieve_t sieve(sqrt(1e9) + 20, true);

const ll MOD = 998244353;
ll a[200005], f[200005];

void solve() {
  ll n, m;
  cin >> n >> m;

  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (ll i = 1; i < n; ++i) {
    if (a[i - 1] % a[i] != 0) {
      cout << "0\n";
      return;
    }
  }

  f[0] = 1;
  for (ll i = 1; i < n; ++i) {
    auto primes = sieve.factorize(a[i - 1] / a[i]);
    primes.erase(unique(all(primes)), primes.end());
    ll sz = primes.size();
    f[i] = 0;

    for (ll j = 0; j < (1 << sz); ++j) {
      ll cnt = 0;
      ll num = a[i];

      for (ll k = 0; k < sz; ++k) {
        if ((j >> k) & 1) {
          cnt++;
          num *= primes[k];
        }
      }

      if (cnt % 2 == 0) {
        f[i] += (m / num);
      } else {
        f[i] -= (m / num);
      }
    }
  }

  ll ans = 1;
  for (ll i = 1; i < n; ++i) {
    ans = (ans * f[i]) % MOD;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
