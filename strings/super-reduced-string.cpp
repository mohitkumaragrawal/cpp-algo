#include <string>
#include <iostream>
using namespace std;

int main() {
  string s;
  getline(cin, s);

  string ans;
  for (int i = 0; i < s.size(); ++i) {
    if (ans.size() == 0 || s[i] != ans.back()) ans.push_back(s[i]);
    else ans.pop_back();
  }

  cout << ans;
}