#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9 + 7;
int modpow(int x, int y) {
  return !y ? 1 : ((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  // Prime factorization wala sieve;
  vector<int> factor(100005);
  for (int i = 2; i <= 100000; i++) {
    for (int j = i; j <= 100000; j += i) {
      if (factor[j] == 0) {
        factor[j] = i;
      }
    }
  }

  // Calculates the frequencies of distinct prime factors available;
  vector<int> freq(100005);
  for (int i = 1; i <= n; i++) {
    set<int> s;
    int k = arr[i];
    while (k > 1) {
      int v = factor[k];
      k /= v;
      s.insert(v);
    }

    // "s" is a set of all the prime factors of arr[i];

    vector<int> primes;
    for (int nxt : s) {
      primes.push_back(nxt);
    }

    // "primes" is an array of all the distinct prime factors of arr[i];

    // let's say there are 3 prime factors - 2, 3, 5; j: 001 -> 111 -> 2,3,5
    // teno hai: freq[2]++, freq[3]++, freq[5]++, freq[2.3]++, freq[2.5]++,
    // freq[3.5]++, freq[2.3.5]++
    for (int j = 1; j < (1 << (int)primes.size()); j++) {
      int v = 1;
      for (int a = 0; a < (int)primes.size(); a++) {
        if (j & (1 << a)) {
          v *= primes[a];
        }
      }
      freq[v]++;
    }
  }

  // Inclusion exclusion principle;
  int ans = 0;
  for (int i = 2; i <= 100000; i++) {
    set<int> s;
    int k = i;
    while (k > 1) {
      int v = factor[k];
      k /= v;
      s.insert(v);
    }
    if (s.size() % 2 == 1) {
      ans += modpow(2, freq[i]) + mod - 1;
      ans %= mod;
    } else {
      ans -= (modpow(2, freq[i]) + mod - 1) % mod;
      ans += mod * 100;
      ans %= mod;
    }
  }

  ans = modpow(2, n) - 1 - ans;
  ans += 100 * mod;
  ans %= mod;
  cout << ans << "\n";
  return 0;
}
