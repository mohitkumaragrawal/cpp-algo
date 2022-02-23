#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <algorithm>

// sort the stuff using selection sort time complexity: O(n^2)
template <typename _It>
void selectionSort(const _It &begin, const _It &end) {
  // Find the minimum thing in the unsorted portion and swap it to the beginning
  // of the unsorted portion repeat till it's sorted;

  for (auto ubegin = begin; ubegin < end; ++ubegin) {
    auto min = std::min_element(ubegin, end);  // O(n)
    std::swap(*min, *ubegin);                  // constant time; O(1)
  }
}

#endif
