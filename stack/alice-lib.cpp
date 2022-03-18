#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  string ans;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != '\\') {
      ans.push_back(s[i]);
      continue;
    }

    string tmp;
    while (ans.back() != '/') {
      tmp.push_back(ans.back());
      ans.pop_back();
    }
    ans.pop_back();
    ans.append(tmp);
  }
  cout << ans << endl;
}