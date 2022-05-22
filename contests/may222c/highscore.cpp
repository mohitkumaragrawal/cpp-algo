#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max({a, b, c, d}) << endl;
  }
}