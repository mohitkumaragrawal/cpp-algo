#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int lastOccurence(vector<int>& arr, int val) {
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] > val) return i;
  }
  return -1;
}

int firstOccurence(vector<int>& arr, int val) {
  for (int i = arr.size() - 1; i >= 0; --i) {
    if (arr[i] < val) return i;
  }
  return -1;
}

int main() {
  int N;
  cin >> N;

  vector<int> arr(N);
  for (int& i : arr) cin >> i;

  sort(arr.begin(), arr.end());

  vector<int> sum(N);
  sum[0] = arr[0];
  for (int i = 1; i < N; ++i) {
    sum[i] = sum[i - 1] + arr[i];
  }

  bool found = false;

  int low = 1;
  int high = 1e+9;

  while (true) {
    if (low > high) break;

    int mid = low + (high - low) / 2;
    int f = firstOccurence(arr, mid);
    if (f == -1) {
      // handle
      low = mid + 1;
      continue;
    }

    int l = lastOccurence(arr, mid);
    if (l == -1) {
      high = mid - 1;
      continue;
    }

    int leftSum = sum[f];
    int rightSum = sum.back() - sum[l - 1];

    if (leftSum == rightSum) {
      found = true;
      break;
    } else if (leftSum > rightSum) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  if (found) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}