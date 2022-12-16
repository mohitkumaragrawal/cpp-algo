#include <iostream>
#include <vector>
using namespace std;

using ull = uint64_t;

ull binexp(ull base, ull pow, ull p) {
  ull result = 1;
  while (pow > 0) {
    if (pow & 1) {
      pow--;
      result = (result * base) % p;
    } else {
      pow /= 2;
      base = (base * base) % p;
    }
  }

  return result;
}

ull inv_modulo(ull n, ull p) { return binexp(n, p - 2, p); }

int main() {
  ull n, p;
  cin >> n >> p;

  vector<ull> heights(p, 0);
  for (int i = 0; i < n; ++i) {
    ull hi;
    cin >> hi;
    heights[hi % p]++;
  }
  //
  // for (int i = 0; i < p; ++i) {
  //   cout << heights[i] << " ";
  // } cout << endl;
  //
  ull result = heights[0];

  for (int i = 2; i <= p - 2; ++i) {
    if (heights[i] == 0) continue;

    auto inv = inv_modulo(i, p);
    result += max(heights[i], heights[inv]);
    heights[i] = 0;
    heights[inv] = 0;
  }
  cout << result << endl;
}
