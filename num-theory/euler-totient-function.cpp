#include <iostream>
using namespace std;

/**
 *  [Euler's Totient Function]
 * This function counts the number of co-primes from 1-n of the number n;
 * for example:
 * ETF(10) = 4, since (1, 10), (3, 10), (7, 10), (9, 10) are the only pairs of co-primes; 
 */

int euler_phi(int n) {
  int ans = n;
  for (int i = 2; i*i <= n; ++i) {
    if (n % i == 0) {
      // we found our prime number i;
      ans *= (i - 1);
      ans /= i;

      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) {
    ans *= (n-1);
    ans /= n;
  }
  return ans;
}

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, (a%b));
}

int euler_naive_method(int n) {
  int cnt = 0;
  for (int i = 2; i < n; ++i) {
    if (gcd(i, n) == 1) ++cnt;
  }
  return cnt+1;
}

int main() {
  while (true) {
    int i; cin >> i;
    cout << euler_phi(i) << ", " << euler_naive_method(i) << endl;
  }
}