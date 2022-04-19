#include <iostream>
using namespace std;
using ull = unsigned long long;

int main() {
  int T;
  cin >> T;
  while (T--) {
    ull N;
    cin >> N;

    ull prev5power = 1;
    ull exponentOf5 = 0;

    while (true) {
      ull newPow = prev5power * 5;
      ull delta = N / newPow;

      if (delta == 0) break;
      exponentOf5 += delta;
      prev5power = newPow;
    }

    cout << exponentOf5 << endl;
  }
}