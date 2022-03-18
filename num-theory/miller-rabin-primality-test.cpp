#include <iostream>
using namespace std;

using ull = uint64_t;

ull mulmod(ull a, ull b, ull mod) {
  ull result = 0;
  while (b > 0) {
    if (b & 1) {
      b--;
      result = (result + a) % mod;
    } else {
      b /= 2;
      a = (a * 2) % mod;
    }
  }
  return result;
}

ull binexp(ull a, ull b, ull mod) {
  ull result = 1;
  while (b > 0) {
    if (b & 1) {
      b--;
      result = mulmod(result, a, mod);
    } else {
      b /= 2;
      a = mulmod(a, a, mod);
    }
  }
  return result;
}

bool checkEquation(ull p, ull a, ull s, ull d) {
  ull x = binexp(a, d, p);
  if (x == 1 || x == (p-1)) return true;

  for (int r = 1; r < s; ++r) {
    x = mulmod(x, x, p);
    if (x == (p-1)) return true;
  }
  return false;
}

bool isPrime(ull p) {
  if (p == 1) return false;

  ull base[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  if (p < 40) {
    for (int i = 0; i < 12; ++i) {
      if (p == base[i]) return true;
    }
    return false;
  }

  ull d = p - 1;
  ull s = 0;
  while (d % 2 == 0) {
    d /= 2;
    ++s;
  }

  for (int i = 0; i < 12; ++i) {
    if (!checkEquation(p, base[i], s, d)) {
      return false;
    }
  }
  return true;
}

int main() {
  int t; cin >> t;
  while (t--) {
    ull p; cin >> p;
    if (isPrime(p)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}