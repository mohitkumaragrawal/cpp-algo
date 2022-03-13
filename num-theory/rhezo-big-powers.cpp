#include <iostream>
#include <string>

using namespace std;
using ull = uint64_t;

#define mod 1000000007

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

int main() {
  ull a;
  cin >> a;

  string b_str;
  cin >> b_str;

  ull b = 0;
  for (int i = 0; i < b_str.size(); ++i) {
    b = (b + (binexp(10, i, mod-1) * (b_str[b_str.size() - 1 - i] - '0'))) % (mod - 1);
  }

  ull result = binexp(a, b, mod);
  cout << result << endl;
}