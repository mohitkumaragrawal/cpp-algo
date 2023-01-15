#include <iostream>

// Given a sequence in the form of array arr[l] to arr[r] (inclusive) sort them
// using the merge sort method
int count_inversion(int* arr, int l, int r) {
  if (r > l) {
    int mid = (l + r) / 2;

    int leftinv = count_inversion(arr, l, mid);
    int rightinv = count_inversion(arr, mid + 1, r);

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int* leftarr = new int[n1];
    int* rightarr = new int[n2];

    for (int j = 0; j < n1; ++j) {
      leftarr[j] = arr[j + l];
    }

    for (int j = 0; j < n2; ++j) {
      rightarr[j] = arr[mid + 1 + j];
    }

    int left = 0, right = 0, i = l;
    int inv = leftinv + rightinv;

    // We compare when either of pile is empty
    while (left < n1 && right < n2) {
      if (leftarr[left] < rightarr[right]) {
        arr[i] = leftarr[left];
        ++i;
        ++left;
      } else {
        inv += (n1 - left);
        arr[i] = rightarr[right];
        ++i;
        ++right;
      }
    }

    // When the left pile is still not empty
    while (left < n1) {
      arr[i] = leftarr[left];
      ++i;
      ++left;
    }

    // When the right pile is still not empty
    while (right < n2) {
      arr[i] = rightarr[right];
      ++i;
      ++right;
    }

    delete[] leftarr;
    delete[] rightarr;

    return inv;
  }

  return 0;
}

int main() {
  int arr[] = {5, 6, 4, 3, 2, 1};
  int inv = count_inversion(arr, 0, 5);

  std::cout << inv << std::endl;
}
