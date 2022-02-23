#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <utility>

template <typename _It>
void insertionSort(_It begin, _It end) {
  auto ubegin = begin + 1;

  while (ubegin != end) {
    // find a suitable place for the new element
    for (auto it = ubegin; it > begin; --it) {
      if (*it < *(it - 1)) {
        std::swap(*it, *(it - 1));
      }
    }
    ++ubegin;
  }
}

#endif