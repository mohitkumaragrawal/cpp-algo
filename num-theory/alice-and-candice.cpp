// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/lola-and-candies-36b57b1b/
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// find the number of ways n can be partitioned such that
// each no. in the partition is odd and consecutive;

/**
 * we need to find the no. of APs with odd terms and common difference 2,
 * such that sum of the ap is n, now such ap can be represented as
 * {1, 3, 5, ..., (2h - 1)} - {1, 3, 5, ..., (2k - 1)} and their sum is
 * h^2 - k^2, so in the end it comes down to no. of solution of
 * h^2 - k^2 = n, or (h + k)(h - k) = n, here both h and k are positive integers
 * where h > k, now let h + k = d1 (first divisor) and (h - k) = d2 (second
 * divisor) d1 x d2 = n, or we just need to count the no. of divisors of n, but,
 * what if, (h, k) comes out fractional? for that, if we solve for h and k
 * h = (d1 + d2) / 2, so for h to be integral, d1 + d2 should be even,
 *
 * SO IN THE END, IT IS JUST COUNT THE PAIRS OF DIVISORS OF N SUCH THAT
 * THEIR SUM IS EVEN!
 */
int countWays(int n) {
  int ways = 0;

  for (int i = 1; i * i <= n; ++i) {
    if (n % i != 0) continue;
    int d1 = i;
    int d2 = n / i;

    if ((d1 + d2) % 2 == 0) {
      ++ways;
    }
  }
  return ways;
}

int main() {
  int n;
  cin >> n;
  int ways = countWays(n);
  cout << ways;
}