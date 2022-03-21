#include <iostream>
#include <vector>

#define mod 1000000007

using namespace std;
using ull = int64_t;

ull count_ways(ull n, ull k, ull x) {
  ull dpx = 1 ? (x == 1) : 0;
  ull sum = 1;

  for (ull i = 2; i < n; ++i) {
    ull newSum = ((k - 1) * sum) % mod;
    
    ull val = sum - dpx;
    if (val < 0) {
      val += mod;
    }
    dpx = val;    
    sum = newSum;
  }

  ull result = sum - dpx;
  if (result < 0) {
    result += mod;
  }
  return result;
}

int main() {
  ull n, k, x;
  cin >> n >> k >> x;

  cout << count_ways(n, k, x) << endl;
}