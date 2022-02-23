#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
a = "99", b = "99",

sum = [0, 0, 0]

  1  2  3
  4  5  6    Ans: 56088
  -------------
  4  5  6
     8  10  12
        12  15  18

  sum = [4, 13, 28, 27, 18]

  ans = [ 5,6,0,8,8]
*/

// This is the best way!
string multiply(string a, string b) {
  if (a == "0" || b == "0") return "0";
  int m = a.size(), n = b.size();
  int L = m+n;

  vector<int> sum(m+n-1, 0);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      sum[i+j] += (a[i]-'0') * (b[j]-'0');
    }
  }

  int carry = 0;
  for (int i = sum.size() - 1; i > 0; --i) {
    carry = sum[i] / 10;
    sum[i] %= 10;

    sum[i-1] += carry;
  }

  string ans;
  // there is a possibility that sum[0] is two-digit number;
  if (sum[0] > 9) {
    ans.push_back((sum[0]/10)+'0');
    ans.push_back((sum[0]%10) +'0');
  } else {
    ans.push_back(sum[0] + '0');
  }

  for (int i = 1; i < sum.size(); ++i) {
    ans.push_back(sum[i] + '0');
  }
  return ans;
}

int main() {
  cout << multiply("123", "456") << endl;

}