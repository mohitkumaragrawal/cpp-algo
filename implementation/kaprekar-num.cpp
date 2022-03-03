#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_kaprikar_number(long n) {
  long sq = n * n;
  auto sq_str = to_string(sq);
  auto sq_sz = sq_str.size();

  size_t d;
  if (sq_sz & 1) {
    d = (1 + sq_sz) >> 1;
  } else {
    d = (sq_sz >> 1);
  }

  auto right_half = atol(sq_str.substr(sq_sz - d, d).c_str());
  auto left_half = atol(sq_str.substr(0, (sq_sz - d)).c_str());

  if (right_half + left_half == n) return true;
  return false;
}

int main() {
  long p, q;
  cin >> p >> q;

  vector<long> arr;
  for (auto i = p; i <= q; ++i) {
    if (is_kaprikar_number(i)) {
      arr.push_back(i);
    }
  }
  if (arr.empty()) {
    cout << "INVALID RANGE" << endl;
  }

  for (auto el: arr) {
    cout << el << " ";
  } cout << endl;
}