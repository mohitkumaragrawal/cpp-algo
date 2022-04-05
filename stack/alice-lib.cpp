#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  string str;
  cin >> str;

  string ans;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] != '\\') {
      ans.push_back(str[i]);
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
