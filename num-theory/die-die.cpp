#include <iostream>
using namespace std;
using ull = uint64_t;

const ull mod = 1e+9 + 7;

ull binexp(ull base, ull pow, ull m) {
  ull result = 1;
  while (pow > 0) {
    if (pow & 1) {
      pow--;
      result = (result * base) % m;
    } else {
      pow /= 2;
      base = (base * base) % m;
    }
  }
  return result;
}

ull mod_inv(ull n, ull m) {
  return binexp(n, m-2, m);
}

int main() {
  ull t;
  cin >> t;
  while (t--) {
    ull n;
    cin >> n;

    ull d = binexp(2, n-1, mod);
    ull result = mod_inv(d, mod);
    cout << result << endl;
  }
}