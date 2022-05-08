#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int& i : arr) cin >> i;

    vector<int> freq(101, 0);
    for (int x : arr) freq[x]++;

    vector<int> nonz;
    for (int i = 0; i <= 100; ++i) {
      if (freq[i] == 0) continue;
      nonz.push_back(i);
    }

    int low = 0;
    int high = nonz.size() - 1;

    int ansIdx = nonz[high];
    while (true) {
      if (low > high) break;

      int mid = low + (high - low) / 2;

      // number of students who scored less than or equal to nonz[mid];
      int lowScoreres = 0;
      for (int i = 0; i <= nonz[mid]; ++i) {
        lowScoreres += freq[i];
      }

      int highScoreres = N - lowScoreres;
      if (lowScoreres > highScoreres) {
        ansIdx = nonz[mid];

        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    int ans = 0;
    for (int i = 100; i >= ansIdx; --i) {
      ans += freq[i];
    }
    cout << ans << endl;
  }
}