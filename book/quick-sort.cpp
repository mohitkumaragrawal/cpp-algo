#include <iostream>

void display(int * arr, int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << "\t";
  }
  std::cout << std::endl;
}

// [5, 3, 2, 4]
int partition(int* arr, int l, int r) {
  int pivot = arr[r];
  int i = l - 1;

  // loop invariant: arr[l...i] is less than pivot;
  for (int j = l; j < r; ++j) {
    if (arr[j] < pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }

  // after the end of the loop: arr[l...i] is less than pivot and arr[i+1...r] is greater than or equal to pivot;
  // and arr[r] is equal to pivot, because we didn't modify that.

  std::swap(arr[i+1], arr[r]);
  return i+1; // return the new index of pivot
}

// Given a sequence arr[l...r] to sort, l and r are inclusive
void quick_sort(int * arr, int l, int r) {
  if (r > l) {
    int pivotindex = partition(arr, l, r);

    quick_sort(arr, l, pivotindex-1);
    quick_sort(arr, pivotindex+1, r);
  }
}

int main() {
  int arr[] = {5, 4, 3, 2, 1};
  quick_sort(arr, 0, 4);
  display(arr, 5);
}
