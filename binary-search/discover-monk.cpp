#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool binary_search(vector<int>& v, int item) {
  int low = 0;
  int high = v.size() - 1;

  while (true) {
    if (low > high) break;
    int mid = (high + low) / 2;

    if (v[mid] > item) {
      high = mid - 1;
    } else if (v[mid] < item) {
      low = mid + 1;
    } else {
      return true;
    }
  }

  return false;
}

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<int> arr(N);
  for (int& i : arr) cin >> i;
  sort(arr.begin(), arr.end());

  while (Q--) {
    int q;
    cin >> q;

    if (binary_search(arr, q)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}