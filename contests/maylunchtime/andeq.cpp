#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int& i : A) cin >> i;

    int x = A[0];
    for (int i = 1; i < N; ++i) x &= A[i];

    int idx = 0;
    int elements = N;

    while (idx < N) {
      int el = A[idx];

      while (el != x && (idx + 1) < N) {
        idx++;
        el &= A[idx];
        elements--;
      }

      if (el != x) {
        elements--;
        break;
      }

      idx++;
    }

    cout << N - elements << endl;
  }
}