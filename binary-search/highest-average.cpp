#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long N;
  cin >> N;
  vector<long long> arr(N);
  for (long long& i : arr) cin >> i;

  sort(arr.begin(), arr.end());

  vector<long long> sum(N);
  sum[0] = arr[0];
  for (long long i = 1; i < N; ++i) {
    sum[i] = sum[i - 1] + arr[i];
  }

  long long Q;
  cin >> Q;

  while (Q--) {
    long long x;
    cin >> x;

    long long ans = 0;

    long long low = 0;
    long long high = N - 1;

    while (true) {
      if (low > high) break;

      long long mid = low + (high - low) / 2;

      if (sum[mid] < (mid + 1) * x) {
        // find larger mid;
        ans = mid + 1;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    cout << ans << endl;
  }
}