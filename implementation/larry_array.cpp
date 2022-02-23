#include <iostream>
#include <vector>
using namespace std;

int valid3[][3] = {
  {1,2,3}, {3,1,2}, {2,3,1}
};

void larry_array(vector<int>& a, int l, int r, int k = 0) {
  int n = r-l+1;

  if (n == 2) {
    if (a[l] < a[l+1]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    return;
  }
  if (n == 3) {
    for (int i = 0; i < 3; ++i) {
      bool m = true;
      for (int j = 0; j < 3; ++j) {
        if (valid3[i][j] != a[l+j]-k) {
          m = false;
        }
      }
      if (m) {
        cout << "YES" << endl;
        return;
      }
    }

    cout << "NO" <<endl;
    return;
  }

  int min_index = -1;
  for (int i = l; i < l+n; ++i) {
    if (a[i] == 1 + k) {
      min_index = i;
      break;
    }
  }

  if (min_index == -1) {
    cout << "Impossible" << endl;
    return;
  }

  while (a[l] != 1+k) { 
    if (min_index == l+1) {
      swap(a[l+1], a[l]);
      swap(a[l+1], a[l+2]);
      min_index = l;
    } else {
      swap(a[min_index], a[min_index-2]);
      swap(a[min_index], a[min_index-1]);
      min_index -= 2;
    }
  }

  int max_index = -1;
  for (int i = l+1; i < l+n; ++i)  {
    if (a[i] == n+k) {
      max_index = i;
      break;
    }
  }

  if (max_index == -1) {
    cout << "Impossible" << endl;
    return;
  }

  while (a[r] != n+k) {
    if (max_index == r-1) {
      swap(a[r-1], a[r]);
      swap(a[r-1], a[r-2]);
      max_index = r;
    } else {
      swap(a[max_index], a[max_index + 2]);
      swap(a[max_index], a[max_index+1]);
      max_index += 2;
    }
  }

  larry_array(a, l+1,r-1, k+1);
}

int main() {
  int t; cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& i: arr) cin >> i;
    larry_array(arr, 0, n-1);
  }
}