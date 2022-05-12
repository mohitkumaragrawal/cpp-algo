#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int A, B, M;
    cin >> A >> B >> M;

    int d1 = abs(A - B);
    int d2 = abs(A - M) + 1 + abs(B - 1);
    int d3 = abs(A - 1) + 1 + abs(M - B);
    int d = min({d1, d2, d3});
    cout << d << endl;
  }
}