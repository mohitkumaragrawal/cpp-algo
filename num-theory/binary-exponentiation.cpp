#include <iostream>
using namespace std;

int binary_exponentiation(int base, int power) {
  if (power < 0) {
    throw exception();
  }
  int result = 1;
  while (power > 0) {
    if (power & 1) {
      result *= base;
      power -= 1;
    } else {
      base *= base;
      power /= 2;
    }
  }
  return result;
}

int main() {
  while (true) {
    int n; cin >> n;
    int p; cin >> p;

    cout << binary_exponentiation(n, p) << endl;
  }
}