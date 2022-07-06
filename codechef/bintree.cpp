#include <algorithm>
#include <iostream>

using namespace std;

#define int long

int distanceBetween(int fromNode, int toNode) {
  int distance = 0;

  while (fromNode != toNode) {
    if (fromNode > toNode) {
      fromNode /= 2;
    } else {
      toNode /= 2;
    }
    distance++;
  }
  return distance;
}

signed main() {
  int T;
  cin >> T;

  while (T--) {
    int f, t;
    cin >> f >> t;

    cout << distanceBetween(f, t) << endl;
  }
}
