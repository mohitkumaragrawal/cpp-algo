#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int countTrailingZeros(int num) {
  int count = 0;

  while ((num & 1) == 0) {
    num /= 2;
    count++;
  }
  return count;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    vector<int> arr(2 * N);
    for (int &i : arr)
      cin >> i;

    int odds = 0;
    vector<int> evens;

    for (auto i : arr) {
      if (i % 2 == 0) {
        evens.push_back(countTrailingZeros(i));
      } else
        odds++;
    }

    if (odds >= N) {
      cout << odds - N << endl;
      continue;
    }

    sort(evens.begin(), evens.end());
    for (auto el : evens)
      cout << el << " ";
    cout << endl;
    int ecount = evens.size() - N;

    int ans = 0;
    for (int i = 0; i < ecount; ++i)
      ans += evens[i];
    cout << ans << endl;
  }
}
