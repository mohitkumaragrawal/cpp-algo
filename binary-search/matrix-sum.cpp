#include <iostream>
#include <vector>
using namespace std;
using ll = int64_t;

bool checkSubMatSum(vector<vector<ll>>& mat, ll sz, ll n, ll k,  ll& l, ll& r) {
  for (int i = 0; i <= (n-sz); ++i) {
    for (int j = 0; j <= (n-sz); ++j) {
      ll sum = 0;
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

ll findSize(vector<vector<ll>>& mat, ll n, ll k,  ll& l, ll& r) {
  ll sz_min = 1;
  ll sz_max = n;

  ll ans = -1;
  while (sz_max >= sz_min) {
    ll sz = (sz_max + sz_min) / 2;

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
  ll n, k;
  cin >> n >> k;

  // n x n matrix;
  vector<vector<ll>> mat(n, vector<ll>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }

  ll l, r;
  ll sz = findSize(mat, n, k, l, r);

  if (sz > 0) {
    cout << "YES" << endl;
    cout << (l+1) << " " << (r+1) << " " << (l + sz) << " " << (r + sz) << endl;
  } else {
    cout << "NO" << endl;
  }
}
