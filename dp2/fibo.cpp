#include <iostream>
#include <vector>
using namespace std;

struct fibonacci_generator {
  vector<int> fib = {0, 1};

  int get_fib(int x) {
    if (fib.size() > x)
      return fib[x];

    int i = fib.size() - 1;
    while (i <= x) {
      int new_val = fib[i] + fib[i - 1];
      fib.push_back(new_val);
      i++;
    }
    return fib[x];
  }
};

struct fibonacci_finder {
  int get_fib(int x) {
    int a = 0, b = 1;

    if (x <= 1)
      return x;

    for (int _ = 1; _ < x; ++_) {
      int nb = a + b;
      a = b;
      b = nb;
    }
    return b;
  }
};

int main() {
  fibonacci_generator fib;
  fibonacci_finder fib2;

  while (true) {
    int x;
    cin >> x;
    cout << fib.get_fib(x) << " ";
    cout << fib2.get_fib(x) << endl;
  }
}
