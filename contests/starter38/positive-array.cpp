#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr) {
  sort(arr.begin(), arr.end());
  vector<int> tmp(100001, 0);

  for (int x: arr) {
    for (int& y: tmp) {
      if (y < x) {
        y++;
        break;
      }
    }
  }

  int cnt = 0;
  for (int y: tmp) {
    if (y == 0) break;
    cnt++;
  }

  cout << cnt << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int& i: arr) cin >> i;
    solve(arr);
  }
}