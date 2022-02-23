#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, k;
  cin >> N >> k;

  vector<int> vec(N);

  for (int i = 0; i < N; ++i) 
    cin >> vec[i];
  
  vector<int> remainderCount(k, 0);
  for (int i = 0; i < N; ++i) {
    auto remainder = vec[i] % k;
    remainderCount[remainder]++;
  }

  int maxSubarraySize = 0;

  for (int r = 0; r <= k/2; ++r) {
    if ((2 * r == k || r == 0) && remainderCount[r] > 0) {
      maxSubarraySize++;
      continue;
    }

    maxSubarraySize += max(remainderCount[r], remainderCount[k-r]);
  }

  cout << maxSubarraySize;
}
