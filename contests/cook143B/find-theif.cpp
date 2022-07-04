#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

#define endl '\n'
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    vector<int> arr(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
      int l, r;
      cin >> l >> r;

      if (i >= l && i <= r) {
        arr[i] -= 10000; // ith person can't be the theif;
      }

      for (int j = l; j <= r; ++j)
        arr[j]++;
    }

    vector<int> theives;
    for (int i = 1; i <= N; ++i) {
      if (arr[i] == N - 1)
        theives.push_back(i);
    }

    cout << theives.size() << endl;
    for (auto x : theives)
      cout << x << endl;
  }
}
