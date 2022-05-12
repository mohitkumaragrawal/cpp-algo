#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;
    vector<int> boxes(N);
    for (int& i : boxes) cin >> i;

    int sum = 0;
    for (int x : boxes) sum += x;

    int m = *min_element(boxes.begin(), boxes.end());

    int ans = sum - N * m;

    cout << ans << endl;
  }
}