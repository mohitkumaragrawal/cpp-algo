#include <iostream>
#include <vector>
using namespace std;
using ull = uint64_t;

bool checkSubMatSum(vector<vector<ull>>& mat, ull sz, ull n, ull k,  ull& l, ull& r) {
  for (int i = 0; i <= (n-sz); ++i) {
    for (int j = 0; j <= (n-sz); ++j) {
      ull sum = 0;
      for (int i1 = 0; i1 < sz; ++i1) {
        for (int j1 = 0; j1 < sz; ++j1) {
          sum += mat[i + i1][j + j1];
        }
      }
      if (sum >= k) {
        l = i;
        r = j;
        return true;
      }
    }
  }
  return false;
}

ull findSize(vector<vector<ull>>& mat, ull n, ull k,  ull& l, ull& r) {
  ull sz_min = 1;
  ull sz_max = n;

  ull ans = -1;
  while (sz_max >= sz_min) {
    ull sz = (sz_max + sz_min) / 2;

    if (checkSubMatSum(mat, sz, n, k, l, r)) {
      ans = sz;
      sz_max = sz - 1;
    } else {
      sz_min = sz + 1;
    }
  }
  return ans;
}

int main() {
  ull n, k;
  cin >> n >> k;

  // n x n matrix;
  vector<vector<ull>> mat(n, vector<ull>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }

  ull l, r;
  ull sz = findSize(mat, n, k, l, r);

  if (sz > 0) {
    cout << "YES" << endl;
    cout << (l+1) << " " << (r+1) << " " << (l + sz) << " " << (r + sz) << endl;
  } else {
    cout << "NO" << endl;
  }
}