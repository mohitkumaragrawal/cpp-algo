#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, b, a;
    cin >> N >> b >> a;

    int a_prime = 0;
    int b_prime = 0;
    int intersection = 0;

    while (N--) {
      int x;
      cin >> x;

      bool alice = (x % a) == 0;
      bool bob = (x % b) == 0;

      if (alice && bob) {
        intersection++;
      } else if (alice && !bob) {
        a_prime++;
      } else if (!alice && bob) {
        b_prime++;
      }
    }

    if (intersection == 0) {
      if (a_prime >= b_prime) {
        cout << "ALICE" << endl;
      } else {
        cout << "BOB" << endl;
      }
    } else {
      if (b_prime >= a_prime) {
        cout << "BOB" << endl;
      } else {
        cout << "ALICE" << endl;
      }
    }
  }
}