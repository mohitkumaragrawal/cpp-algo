#include <cmath>
#include <iostream>

using namespace std;

#define int long

int num_digits(int a, int b, int x) {
  double logba = log((double)a) / log((double)b);
  double logbx = log((double)x) / log((double)b);

  double val = logba + x * logbx;
  cout << "VAL" << val << endl;

  int ans = (int)(1.0 + floor(val));
  cout << "FLOOR " << floor(val) << endl;
  cout << ans << endl;
  return ans;
}

void solve(int a, int b, int n) {
  int low = 1;
  int high = 1e+9;

  // find first occurence of n-digit number
  int first_occurence = -1;
  while (true) {
    if (low > high) break;
    int mid = low + (high - low) / 2;
    int nd = num_digits(a, b, mid);
    cout << "ND: " << nd << endl;
    if (nd < n) {
      low = mid + 1;
    } else if (nd > n) {
      high = mid - 1;
    } else {
      first_occurence = mid;
      high = mid - 1;
    }
  }
  cout << "FIRST : " << first_occurence << endl;

  if (first_occurence == -1) {
    cout << 0 << endl;
    return;
  }

  // find last occurence of n-digit number;
  int last_occurence = -1;
  high = 1e+9;
  low = 1;
  while (true) {
    if (low > high) break;
    int mid = low + (mid - low) / 2;

    int nd = num_digits(a, b, mid);
    if (nd < n) {
      low = mid + 1;
    } else if (nd > n) {
      high = mid - 1;
    } else {
      first_occurence = mid;
      high = mid + 1;
    }
  }

  int ans = last_occurence - first_occurence + 1;
  cout << ans << endl;
}

signed main() {
  freopen("base-number.txt", "r", stdin);
  int T = 0;
  while (!cin.eof()) {
    int a, n, b;
    T++;
    cin >> a >> n >> b;
    solve(a, b, n);
  }
}
