#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
  char comma[3] = {'\0', ' ', '\0'};

  out.put('[');
  for (auto el : vec) {
    out << comma << el;
    comma[0] = ',';
  }
  out.put(']');
  return out;
}

void quick_sort(std::vector<int>& arr, int l, int r) {
  if (r > l) {
    // partition code:
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; ++j) {
      if (arr[j] < pivot) {
        i++;
        std::swap(arr[i], arr[j]);
      }
    }

    // after loop we have arr[l...i] is less than pivot; and arr[i+1 ... r] is greater than or equal to pivot
    // and arr[r] is pivot;
    std::swap(arr[i+1], arr[r]);

    int pivotindex = i + 1;

    quick_sort(arr, l, pivotindex-1);
    quick_sort(arr, pivotindex+1, r);
  }  
}

void quick_sort(std::vector<int>& arr) {
  quick_sort(arr, 0, arr.size() - 1);
}

int main() {
  std::vector arr = { 5, 4, 3, 2, 1};
  quick_sort(arr);

  std::cout << arr << std::endl;
}
