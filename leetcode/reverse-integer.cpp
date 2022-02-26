#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    if (x < 0) {
      if (x == INT_MIN) {
        // this can't be negated;
        return 0;
      }
      return -reverse(-x);
    }
    int result = 0;

    while (x > 0) {
      long newResult = (result * 10l) + (x%10);
      if (newResult > INT_MAX) return 0;

      result = newResult;
      x /= 10;
    }
    return result;
  }
};