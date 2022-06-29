#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    int minA = 0, minB = 0;
    int type, first, second;

    for (int i = 0; i < N; ++i) {
      cin >> type >> first >> second;

      if (type == 1) {
        minA = first;
        minB = second;
        cout << "YES" << endl;
        continue;
      }

      int A, B;

      if (first < minA || second < minB) {
        B = first;
        A = second;
        cout << "YES" << endl;
        minA = A;
        minB = B;
      } else if (first < minB || second < minA) {
        A = first;
        B = second;
        cout << "YES" << endl;
        minA = A;
        minB = B;
      } else {
        minA = min(first, second);
        minB = minA;

        if (first == second) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      }
    }
  }
}
