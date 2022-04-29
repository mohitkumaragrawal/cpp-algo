#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  string str;
  cin >> str;

  vector<int> zero_count(N + 1), one_count(N + 1);
  zero_count[0] = one_count[0] = 0;

  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == '0') {
      zero_count[i + 1] = zero_count[i] + 1;
      one_count[i + 1] = one_count[i];
    } else {
      zero_count[i + 1] = zero_count[i];
      one_count[i + 1] = one_count[i] + 1;
    }
  }

    cout << ans << endl;
}