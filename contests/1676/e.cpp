#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int& i : a) cin >> i;

    sort(a.begin(), a.end(), greater<int>());

    vector<int> sum(n);
    sum[0] = a[0];

    for (int i = 1; i < n; ++i) {
      sum[i] = sum[i - 1] + a[i];
    }

    while (q--) {
      int x;
      cin >> x;
      int ans = -1;

      int low = 0;
      int high = n - 1;

      while (true) {
        if (low > high) break;

        int mid = (low + high) / 2;
        if (sum[mid] >= x) {
          ans = mid + 1;
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }

      cout << ans << endl;
    }
  }
}