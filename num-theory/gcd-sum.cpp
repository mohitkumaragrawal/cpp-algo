#include <iostream>
#include <vector>
#include <array>
using namespace std;
array<int, 1000001> phi;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int gcdSum(int n) {
  int result = 0;

  for (int i = 1; i * i <= n; ++i) {
    if (n % i != 0) continue;
    int d1 = i;
    int d2 = n / i;

    result += d1 * phi[n/d1];
    if (d1 != d2) {
      result += d2 * phi[n/d2];
    }
  }
  return result;
}

int gcdSumBruteForce(int n) {
  int result = 1;
  for (int i = 2; i <= n; ++i) {
    result += gcd(n, i);
  }
  return result;
}


int main() {
  for (int i = 1; i < phi.size(); ++i) {
    phi[i] = i;
  }

  for (int i = 2; i < phi.size(); ++i) {
    if (phi[i] != i) continue;

    phi[i] = i - 1;
    for (int j = 2*i; j < phi.size(); j+=i) {
      phi[j] /= i;
      phi[j] *= i-1;
    }
  }

  while (true) {
    int n; cin >> n;
    int r1 = gcdSumBruteForce(n), r2 = gcdSum(n);
    cout << "bruteforce: " << r1 << ", optimized: " << r2 << endl;
  }
}