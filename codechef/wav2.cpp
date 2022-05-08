#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, Q;
  cin >> N >> Q;

  vector<int> arr(N);
  for (int& i : arr) cin >> i;

  sort(arr.begin(), arr.end());

  while (Q--) {
    int x;
    cin >> x;

    int low = 0;
    int high = arr.size() - 1;

    if (arr[high] < x) {
      cout << "POSITIVE" << endl;
      continue;
    }

    int ansIdx = high;

    while (true) {
      if (low > high) break;

      int mid = low + (high - low) / 2;

      if (arr[mid] >= x) {
        ansIdx = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    if (arr[ansIdx] == x) {
      cout << "0" << endl;
      continue;
    }

    int Count = N - ansIdx;
    if (Count & 1) {
      cout << "NEGATIVE" << endl;
    } else {
      cout << "POSITIVE" << endl;
    }
  }
}