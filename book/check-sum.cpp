#include <vector>
#include <iostream>

/**
 * Given an array, arr[0...n] and a number X.
 * find if there exists two numbers x1 and x2 in arr such that their sum
 * is exactly X
 **/ 

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

// This is just similar to merge-sort
bool check_sum(std::vector<int>& vec, int sum) {
  // If the sequence has less than 2 elements, return false;
  if (vec.empty() || vec.size() == 1) return false;

  int mid = vec.size() / 2;

  // Create two subvector, from [0...mid-1] and [mid...n-1] where n is the size of original vector.
  auto leftvec = std::vector<int>(vec.begin(), vec.begin() + mid);
  auto rightvec = std::vector<int>(vec.begin() + mid, vec.end());

  // We check if either of the subarray elements can be added to the get the required sum,
  // if that's the case we just return true; nothing else needs to be done;
  if (check_sum(leftvec, sum) || check_sum(rightvec, sum)) {
    return true;
  };

  // when check_sum returns false it sorts the input array using merge-sort
  // so here, both leftvec and rightvec are sorted in increasing order.

  // `i` is the iterator on leftvec.
  // `j` is the iterator on rightvec.
  // `k` is the iterator on original vec.
  int i = 0, j = 0, k = 0;

  // here leftvec[i] + rightvec[j], never decreases when either of i or j increases
  // because both leftvec and rightvec are sorted.
  while (i < leftvec.size() && j < rightvec.size()) {
    
    // While merging both sorted arrys if we encounter that we find the two numbers
    // who sum is the required sum, we just return true;
    if (leftvec[i] + rightvec[j] == sum) {
      std::cout << leftvec[i] << " + " << rightvec[j] << " = " << sum << std::endl;
      return true;
    }

    // else we continue with the merging step because remember that this function sorts
    // the input when there doesn't exist any two numbers in the sequence whose sum is 
    // exactly the required sum.
    if (leftvec[i] < rightvec[j]) {
      vec[k] = leftvec[i];
      ++i; ++k;
    } else{
      vec[k] = rightvec[j];
      ++j; ++k;
    }
  }

  // just add the remaining elements!
  while (i < leftvec.size()) {
    vec[k] = leftvec[i];
    ++i; ++k;
  }

  while (j < rightvec.size()) {
    vec[k] = rightvec[j];
    ++j; ++k;
  }

  // here vec is sorted in ascending order
  return false;
}

int main() {
  std::vector test = { 5, 2, 4, 7, 1, 3, 2, 6 };

  std::cout << test << std::endl;
  
  while (true) {
    int s;
    std::cin >> s;

    // the function modifies the vector in order to get the result
    // so we create a temporary copy, so we can get our answer without
    // modifying the input array.
    auto copyvec = std::vector<int>(test);
    if (check_sum(copyvec, s)) {
      std::cout << "This sum is possible" << std::endl;
    } else {
      std::cout << "This sum is not possible" << std::endl;
    }
  }
}