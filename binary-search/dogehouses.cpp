#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int calculateAnswer(int y1, int y2, const vector<int>& yfreq,
                    const vector<int>& arr) {
  int ans = yfreq[y1] + yfreq[y2];

  int x1 = 0, x2 = 1000;

  int ymax = max(y1, y2);
  int ymin = min(y1, y2);
  for (;; ++x1) {
    if (arr[x1] == y1) break;
    if (arr[x1] > ymin && arr[x1] < ymax) {
      ans++;
      break;
    }
  }
  for (;; --x2) {
    if (arr[x2] == y2) break;
    if (arr[x2] > ymin && arr[x2] < ymax) {
      ans++;
      break;
    }
  }
  return ans;
}

int main() {
  int N;
  cin >> N;

  vector<int> arr(N);
  for (int& i : arr) cin >> i;

  vector<int> yfreq(1001, 0);
  for (int i : arr) {
    yfreq[i]++;
  }

  int y1 = 0, y2 = 0;
  for (int i = 0; i <= 1000; ++i) {
    if (yfreq[y1] < yfreq[i]) {
      y1 = i;
    }
  }

  if (y1 == 0) y2 = 1;
  for (int i = 0; i <= 1000; ++i) {
    if (i == y1) continue;
    if (yfreq[y2] < yfreq[i]) {
      y2 = i;
    }
  }

  int ans = calculateAnswer(1, 4, yfreq, arr);

  cout << ans << endl;
}