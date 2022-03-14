#include <iostream>
#include <vector>
using namespace std;

using ull = uint64_t;

ull lines_of_wines(vector<ull>& wines, ull l, ull r, ull k = 1) {
  if (r == l) {
    return k * wines[l];
  }

  ull first = k * wines[l] + lines_of_wines(wines, l+1, r, k+1);
  ull second = k * wines[r] + lines_of_wines(wines, l, r-1, k+1);
  return max(first, second);
}

int main() {
  ull n; cin >> n;
  vector<ull> wines;
  while (n--) {
    ull w; cin >> w;
    wines.push_back(w);
  }

  ull result = lines_of_wines(wines, 0, wines.size()-1);
  cout << result << endl;
}