#include <iostream>

void display(int * arr, int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << "\t";
  }
  std::cout << std::endl;
}

// assumes two sorted sequences arr[l] to arr[mid] and arr[mid+1] to arr[r]
// and merges them inplace in the arr
void merge(int* arr, int l, int mid, int r) {
  int n1 = mid - l + 1;
  int n2 = r - mid;

  int* leftarr = new int[n1];
  int* rightarr = new int[n2];

  for (int j = 0; j < n1; ++j) {
    leftarr[j] = arr[j+l];
  }

  for (int j = 0; j < n2; ++j) {
    rightarr[j] = arr[mid + 1 + j];
  }

  int left = 0, right = 0, i = l;

  // We compare when either of pile is empty
  while (left < n1 && right < n2) {
    if (leftarr[left] < rightarr[right]) {
      arr[i] = leftarr[left];
      ++i; ++left;
    } else {
      arr[i] = rightarr[right];
      ++i; ++right;
    }
  }

  // When the left pile is still not empty
  while (left < n1) {
    arr[i] = leftarr[left];
    ++i; ++left;
  }

  // When the right pile is still not empty
  while(right < n2) {
    arr[i] = rightarr[right];
    ++i; ++right;
  }

  delete leftarr;
  delete rightarr;
}

// Given a sequence in the form of array arr[l] to arr[r] (inclusive) sort them using the merge sort method
void merge_sort(int* arr, int l, int r) {
  if (r > l) {
    int mid = (l + r) / 2;

    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, r);

    merge(arr, l, mid, r);
  }
}

int main() {
  int arr[] = {10, 20, 30, 40, 50, 3, 6, 9, 12, 15};
  int n = sizeof(arr)/ sizeof(int);
  display(arr, n);

  merge(arr, 0, 4, 9);
  display(arr, n);

  int arr2[] = {7, 8, 9, 1, 2, 5, 0, 25, 23, 10, 6, 0};
  int n2 = sizeof(arr2)/sizeof(int);
  display(arr2, n2);

  std::cout << "Merge Sort: " << std::endl;
  merge_sort(arr2, 0, n2-1);
  display(arr2, n2);
}