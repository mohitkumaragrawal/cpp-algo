#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int calc(int x, int y, int m) {
  int md = (x - y) % m;
  while (md < 0) md += m;
  return x + y + md;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int& i : arr) cin >> i;

    sort(arr.begin(), arr.end(), greater<int>());

    // for (int i = 0; i < n; ++i) {
    //   for (int j = 0; j < n; ++j) {
    //     int md = (arr[i] - arr[j]) % m;
    //     if (md < 0) md += m;
    //     int val = arr[i] + arr[j] + md;
    //     cout << val << "\t";
    //   }
    //   cout << endl;
    // }

    int ans = INT_MIN;

    for (int i = 0; i < n; ++i) {
      ans = max({ans, calc(arr[0], arr[i], m), calc(arr[i], arr[0], m)});
    }

    cout << ans << endl;
  }
}