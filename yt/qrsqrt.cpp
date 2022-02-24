#include <iostream>

float Q_rsqrt(float num) {
  long i;
  float x2, y;
  const float threehalfs = 1.5f;

  x2 = num * 0.5f;
  y = num;

  i = *(long*) &y;             // Evil bit hack
  i = 0x5f3759df - (i >> 1);  // What the f?
  y = *(float*) &i;
  y = y * (threehalfs - (x2*y*y)); // Newton's iteration
  y = y * (threehalfs - (x2*y*y));
  return y;
}

int main() {
  float n;
  std::cin >> n;
  auto ans = Q_rsqrt(n);

  std::cout << ans << std::endl;
}