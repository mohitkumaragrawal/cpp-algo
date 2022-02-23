/**
 * Given an array arr[0...N] find the contigous subarray of arr, let's
 * says arr* such that the sum of elements of this subarray is maximum.
 */ 

#include <iostream>
#include <algorithm>

// Simple struct to store the necessary details;
struct subarr {
  // left index in the arr where the subarray begins (inclusive)
  int left;

  // right index in the arr where the subarray ends (inclusive)
  int right;

  // sum of all the elements arr[left...right]
  int sum = 0;
};

bool operator>(const subarr& a, const subarr& b) {return a.sum > b.sum; }
bool operator<(const subarr& a, const subarr& b) {return a.sum < b.sum; }
bool operator==(const subarr& a, const subarr& b) {return a.sum == b.sum; }

std::ostream& operator<<(std::ostream& out, const subarr& arr) {
  out << "[" << arr.left << "-" << arr.right <<"]: " << arr.sum;
  return out;
}

subarr find_max_subarray(int* arr, int l, int r) {
  if (l == r) {
    return {
      l, r, arr[l]
    };
  }

  if (l < r) {
    int mid = (l + r) / 2;

    const auto lhalf = find_max_subarray(arr, l, mid);
    const auto rhalf = find_max_subarray(arr, mid+1, r);

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int left_lastsum = arr[mid];
    int left_max = left_lastsum;
    int left_index = mid;
    for (int j = 1; j < n1; ++j) {
      left_lastsum = left_lastsum + arr[mid - j];
      if (left_lastsum > left_max) {
        left_max = left_lastsum;
        left_index = mid - j;
      }
    }

    int right_lastsum = arr[mid+1];
    int right_max = right_lastsum;
    int right_index = mid + 1;
    for (int j = 1; j < n2; ++j) {
      right_lastsum = right_lastsum + arr[mid + j + 1];
      if (right_lastsum > right_max) {
        right_max = right_lastsum;
        right_index = mid + j + 1;
      }
    }

    const subarr across_mid = {left_index, right_index, left_max + right_max};

    return std::max({lhalf, rhalf, across_mid});
  }
  return {-1, -1, 0}; // we have empty arr;
}

int main() {
  freopen("./max-subarray.txt", "r", stdin);

  int testcases;
  std::cin >> testcases;

  for (int j = 0; j < testcases; ++j) {
    int N;
    std::cin >> N;

    int* arr = new int[N];
    for (int i = 0; i < N; ++i) {
      std::cin >> arr[i];
    }

    auto max_subarray = find_max_subarray(arr, 0, N-1);
    std::cout << "[" << j << "] " << max_subarray << std::endl;

    delete arr;
  }
}