#include <iostream>
using namespace std;

void solve() {
  int r, c, k;
  cin >> r >> c >> k;

  int right = r + k;
  if (right > 8) right = 8;

  int left = r - k;
  if (left < 1) left = 1;

  int top = c - k;
  if (top < 1) top = 1;

  int bottom = c + k;
  if (bottom > 8) bottom = 8;

  int ans = (right - left + 1) * (bottom - top + 1);
  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;

  while (T--) solve();
}