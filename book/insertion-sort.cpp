#include <iostream>

#define Length(arr) (sizeof(arr)/sizeof(int))

void insertion_sort(int* arr, int n) {
  for (int j = 1; j < n; ++j) {
    int i = j - 1;
    int key = arr[j];

    while (i >= 0 && arr[i] > key) {
      arr[i+1] = arr[i];
      i--;
    }

    arr[i+1] = key;
  }
}

void insertion_sort_dec(int* arr, int n) {
  for (int j = 1; j < n; ++j) {
    int key = arr[j];
    int i = j - 1;

    while (i >= 0 && arr[i] < key) {
      arr[i+1] = arr[i];
      i--;
    }

    arr[i+1] = key;
  }
}

void display(int * arr, int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int arr[] = {5, 4, 3, 2, 1};
  int n = Length(arr);

  display(arr, n);

  insertion_sort(arr, n);
  display(arr, n);

  insertion_sort_dec(arr, n);
  display(arr, n);
}