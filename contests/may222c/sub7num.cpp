#include <iostream>
#include <vector>
using namespace std;

#define mod 1000000007

int power10[6] = {1, 3, 2, 6, 4, 5};

int p10(int x) {
  x %= 6;
  return power10[x];
}

void solve() {
  int N;
  cin >> N;

  vector<int> arr(N);
  for (int& x : arr) cin >> x;
}

int main() {
  int T;
  cin >> T;

  while (T--) solve();
}