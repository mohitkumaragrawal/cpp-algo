#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& first, vector<int>& second) {
    vector<int> merged;

    auto firstIt = first.begin();
    auto secondIt = second.begin();

    while (firstIt != first.end() && secondIt != second.end()) {
      if (*firstIt > *secondIt) {
        merged.push_back(*secondIt);
        ++secondIt;
      } else {
        merged.push_back(*firstIt);
        ++firstIt;
      }
    }
    while (firstIt != first.end()) {
      merged.push_back(*firstIt);
      ++firstIt;
    }
    while (secondIt != second.end()) {
      merged.push_back(*secondIt);
      ++secondIt;
    }

    auto mid = merged.size() / 2;
    if (merged.size() % 2 == 0) {
      return (double) (merged[mid] + merged[mid - 1]) / 2.0;
    } else {
      return (double) merged[mid];
    }
  }
};

int main() { 

}