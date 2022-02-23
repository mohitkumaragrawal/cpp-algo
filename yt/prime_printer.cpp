#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> p(n + 1, 0);

  for (int i = 2; i <= n; ++i) {
    if (p[i] == 0) {
      // This must be print number, mark all of its factor

      for (int j = i * i; j <= n; j += i) {
        p[j] = 1;
      }

      std::cout << i << " " << std::endl;
    }
  }
}