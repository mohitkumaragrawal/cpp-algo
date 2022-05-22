#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (auto& x : arr) cin >> x;

    int deg = N - 1;
    while (arr[deg] == 0) deg--;
    cout << deg << endl;
  }
}