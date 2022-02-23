#include <vector>
#include <iostream>

int solve(const std::vector<int>& arr, int l, int r, int u) {
  if (l >= r) {
    return 0;
  }

  int m = l;
  for (int i = l; i <= r; ++i) {
    if (arr[m] < arr[i]) m = i;
  }

  if (u == -1) {
    int ans = solve(arr, l, m-1, m) + solve(arr, m+1, r, m) + m;
    return ans;
  }

  if (u > m) {
    return (u - m) * arr[u] + solve(arr, l, m-1,m);
  }

  if (u < m) {
    return (m - u) * arr[u] + solve (arr, m+1, r,m);
  }

  return 0;
}

int trapping_rainwater(std::vector<int> arr) {
  int total = 0;
  for (auto i: arr) total+= i;

  int filled = solve(arr, 0, arr.size() - 1, -1);
  return filled - total;
}

int main() {
  freopen("trapping-rainwater.txt", "r", stdin);
  using namespace std;

  int N;
  cin >> N;

  vector<int> arr(N);
  for (auto& i: arr) cin >> i;

  std::cout << trapping_rainwater(arr);
}