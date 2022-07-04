#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    if (N == 1) {
      cout << 1 << endl;
      continue;
    }
    int right = N;
    int left = 1;

    bool wasRight = false;
    while (right >= left) {
      if (wasRight) {
        cout << left << " ";
        left++;
        wasRight = false;
      } else {
        cout << right << " ";
        right--;
        wasRight = true;
      }
    }
    cout << endl;
  }
}
