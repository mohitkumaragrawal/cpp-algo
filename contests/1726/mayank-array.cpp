#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (auto& el: arr) cin >> el;

    if (N == 1) {
      cout << 0 << endl;
      continue;
    }

    int last = arr.back(), first = arr.front();
    int ans1 = last - first;
    int ans2 = last - *min_element(arr.begin(), arr.end()-1);
    int ans3 = *max_element(arr.begin() + 1, arr.end()) - first;

    int ans = max({ans1, ans2, ans3});
    for (int i = 0; i < N; ++i) {
      int j = (i + N - 1) % N;
      ans = max(ans, arr[j] - arr[i]); 
    }

    cout << ans << endl;
  }
}