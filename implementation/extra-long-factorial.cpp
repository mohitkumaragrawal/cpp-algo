#include <iostream>
#include <string>
#include <vector>

using namespace std;

string big_int_multiply(const string& a, const string& b) {
  auto a_sz = a.size(), b_sz = b.size();
  vector<int> arr(a_sz + b_sz - 1, 0);

  for (int i = 0; i < a_sz; ++i) {
    for (int j = 0; j < b_sz; ++j) {
      arr[i+j] += (a[i] - '0') * (b[j] - '0');
    }
  }
  for (int i = (a_sz + b_sz - 2); i > 0; --i) {
    if (arr[i] > 9) {
      arr[i-1] += (arr[i] / 10);
      arr[i] %= 10;
    }
  }
  string ans = to_string(arr[0]);
  for (int i = 1; i < arr.size(); ++i) {
    ans.push_back(arr[i] + '0');
  }
  return ans;
}

int main() {
  int n; 
  cin >> n;

  string factorial = "1";
  for (int i = 2; i <= n; ++i) {
    factorial = big_int_multiply(factorial, to_string(i));
  }
  cout << factorial << endl;
}