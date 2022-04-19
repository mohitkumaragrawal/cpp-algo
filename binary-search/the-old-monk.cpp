#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// returns the largest index of element greater than equal to el;
// arr is decreasing;
int binarySearch(vector<long>& arr, long el, int left, int right) {
  int result = -1;

  while (right >= left) {
    int mid = left + (right - left) / 2;
    if (arr[mid] >= el) {
      result = mid;
      left = mid + 1;
    } else {  // arr[mid] < el
      right = mid - 1;
    }
  }

  return result;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<long> A(N), B(N);

    for (auto& ai : A) cin >> ai;
    for (auto& bi : B) cin >> bi;

    int ans = 0;
    for (int i = 0; i < N; ++i) {
      int j = binarySearch(B, A[i], i, N - 1);
      ans = max(ans, (j - i));
    }

    cout << ans << endl;
  }
}