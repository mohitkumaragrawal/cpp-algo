#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, X;
    cin >> N >> X;
    vector<int> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    int multiTarget = *max_element(h.begin(), h.end());

    int singleTarget = 0;
    for (int i = 0; i < N; ++i) {
      singleTarget += h[i] / X;
      if (h[i] % X != 0) singleTarget++;
    }

    int ans = min(singleTarget, multiTarget);
    cout << ans << endl;
  }
}