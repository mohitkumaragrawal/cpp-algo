#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, X;
    cin >> N >> X;

    vector<int> arr(N);
    for (int& x : arr) cin >> x;

    bool e = false, g = false, l = false;
    for (int x : arr) {
      if (x > X) g = true;
      if (x < X) l = true;
      if (x == X) e = true;
    }

    if (e) {
      cout << "YES" << endl;
      continue;
    }

    if (!g || !l) {
      cout << "NO" << endl;
      continue;
    }

    cout << "YES" << endl;
  }
}