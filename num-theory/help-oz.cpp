#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  int M;
  cin >> M;

  vector<int> arr(M);
  for (int i = 0; i < M; ++i) cin >> arr[i];

  int m = *min_element(arr.begin(), arr.end());
  int g = arr[0] - m;

  for (int el: arr) {
    g = gcd(g, el-m);
  }

  cout << g << endl;

  for (int i = 2; i <= g; ++i) {
    if (g%i == 0) cout << i << " ";
  }
}