#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  vector<int> A, B;
  int c = 1;

  while (T--) {
    int N;
    cin >> N;

    while (A.size() < N) {
      A.push_back((c << 2));
      A.push_back((c << 2) | 1);
      B.push_back((c << 2) | 2);
      B.push_back((c << 2) | 3);
      c++;
    }

    for (int i = 0; i < N; ++i) {
      cout << A[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < N; ++i) {
      cout << B[i] << " ";
    }
    cout << endl;
  }
}