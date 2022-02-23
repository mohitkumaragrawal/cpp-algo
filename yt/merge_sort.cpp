#include <vector>
#include <algorithm>
#include <iostream>

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

void merge_sort(std::vector<int>& lst, int left, int right) {
  if (left >= right) {
    return;
  }

  int mid = (left + right) / 2;
  merge_sort(lst, left, mid);
  merge_sort(lst, mid+1, right);

  auto left_half = std::vector<int>(lst.begin() + left, lst.begin() + mid + 1);
  auto right_half = std::vector<int>(lst.begin() + mid + 1, lst.begin() + right + 1);

  int l = 0, r = 0, k = left;
  
  while (l < left_half.size() && r < right_half.size()) {
    if (left_half[l] < right_half[r]) {
      lst[k] = left_half[l];
      k++; l++;
    } else {
      lst[k] = right_half[r];
      k++; r++;
    }
  }

  while (l < left_half.size()) {
    lst[k] = left_half[l];
    l++; k++;
  }

  while (r < right_half.size()) {
    lst[k] = right_half[r];
    k++; r++;
  }
}

int main() {
  std::vector arr {2, 1, 5, 0, 0, 0, 0, 0};
  merge_sort(arr, 0, arr.size() - 1);

  std::cout << arr << std::endl;
}