#include <iostream>
using namespace std;
using ull = uint64_t;

ull ceil_division(ull n, ull d) {
  ull result = n / d;
  if (n % d > 0) {
    result++;
  }
  return result;
}

ull count_even(ull l, ull r, ull E) {
  ull k1;
  
  if (E * E >= l) {
    k1 = E;
  } else {
    k1 = ceil_division(l, E);
    if (k1 & 1) k1++;
  }

  ull k2 = r / E;
  if (k2 & 1) k2--;

  if (k2 < k1) return 0;
  return (k2 - k1) / 2 + 1;
}

ull count_odd(ull l, ull r, ull O) {
  ull k1;
  if (O*O >= l) {
    k1 = O;
  } else {
    k1 = ceil_division(l, O);
    if (k1 % 2 == 0) k1++;
  }

  ull k2 = r / O;
  if (k2 % 2 == 0) k2--;

  if (k2 < k1) return 0;
  return (k2 - k1) / 2 + 1;
}

ull solve(ull l, ull r) {
  ull result = 0;

  for (ull i = 1; i * i <= r; ++i) {
    ull delta;
    if (i & 1) {
      delta = count_odd(l, r, i);
    } else {
      delta = count_even(l, r, i);
    }
    //cout << i << ": " << delta << endl;
    result += delta;
  }
  return result;
}

int main() {
  int t; cin >> t;
  while (t--) {
    ull l, r;
    cin >> l >> r;
    cout << solve(l, r) << endl;
  }
}