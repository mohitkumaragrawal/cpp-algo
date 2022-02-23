#include <iostream>

int countPaths(int start, int end) {
  if (end < start) return 0;
  if (end == start) return 1;
  if ((end - start) == 1) return 1;

  int result = 0;
  for (int j = 1; j <= 6; ++j) {
    result += countPaths(start + j, end);
  }

  return result;
}

int main() { std::cout << countPaths(0, 4); }