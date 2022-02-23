#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <utility>

template <typename _It>
void bubbleSort(_It begin, _It end) {
  auto uend = end;  // unsorted end;

  while (uend != begin) {  // run till the list is unsorted
    for (auto it = begin; it < uend; ++it) {
      if (*it > *(it + 1)) {  // stuffs are in wrong order swap them.
        std::swap(*it, *(it + 1));
      }
    }
    uend--;
  }
}

#endif