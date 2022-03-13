#include <iostream>
#include <vector>
#include <array>
#include <map>
using namespace std;

using ull = uint64_t;
#define mod 1000000007
#define UL 100000

ull binexp(ull base, ull power) {
  ull result = 1;
  while (power > 0) {
    if (power & 1) {
      power--;
      result = (result * base) % mod;
    } else {
      power /= 2;
      base = (base * base) % mod;
    }
  }
  return result;
}

ull mod_inv(ull n) {
  return binexp(n, mod-2);
}

array<ull, UL+1> fac_array;
ull factorial(ull n) {
  return fac_array[n];  
}
void factorial_init() {
  fac_array[0] = 1;
  for (int i = 1; i <= UL; ++i) {
    fac_array[i] = (i * fac_array[i-1]) % mod;
  }
}

int main() {
  factorial_init();
  ull faculties; cin >> faculties;

  ull result = 1;
  ull total_courses = 0;
  for (ull i = 0; i < faculties; ++i) {
    
    ull m; cin >> m;

    // m is the number of courses taught by ith professor;
    total_courses += m;
    result = (result * mod_inv(factorial(m))) % mod;

    map<int, int> cp_freq;
    for (ull j = 0; j < m; ++j) {
      int cp;
      cin >> cp;
      cp_freq[cp]++;
    }

    for (auto p: cp_freq) {
      result = (result * factorial(p.second)) % mod;
    }
  }

  result = (result * factorial(total_courses)) % mod;
  cout << result << endl;
}