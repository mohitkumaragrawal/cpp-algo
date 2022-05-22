#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> d(N);
    for (int& i : d) cin >> i;

    int cnt = 0;
    for (auto x : d) {
      if (x >= 1000) x++;
    }
    cout << cnt << endl;
  }
}