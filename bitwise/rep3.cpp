#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  // because we have 32 bit integer
  // stores the number of ones in each bit position;
  int count[32];

  for (int i = 0; i < 32; ++i)
    count[i] = 0;

  // input N integers
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;

    for (int j = 0; j < 32; ++j) {
      bool hasBit = (x & (1 << j)) != 0;
      if (hasBit)
        count[j]++;
    }
  }

  // now find that number, count[i] should be either of form (3n) or (3n + 1)
  int ans = 0;
  for (int j = 0; j < 32; ++j) {
    ans |= (count[j] % 3) << j;
  }
  cout << ans << endl;
}
