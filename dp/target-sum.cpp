#include <iostream>
#include <vector>

using namespace std;

int target_sum(vector<int>& arr, int target, int start) {
  if (start == arr.size() - 1) {
    if (abs(arr[start]) == abs(target)) {
      return 1;
    } else {
      return 0;
    }
  }

  int c1 = target_sum(arr, target - arr[start], start+1);
  int c2 = target_sum(arr, target + arr[start], start+1);

  return c1 + c2;
}

int main() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int &i: arr) cin >> i;
  int sum;
  cin >> sum;

  cout << target_sum(arr, sum, 0) << endl;
}
