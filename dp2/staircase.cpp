#include <iostream>
#include <vector>
using namespace std;

int find_ways_dp(int x) {
  if (x == 0 || x == 1)
    return 1;
  int a = 1, b = 1;

  for (int i = 0; i < x - 1; ++i) {
    int newb = a + b;
    a = b;
    b = newb;
  }
  return b;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    cout << find_ways_dp(N) << endl;
  }
}
