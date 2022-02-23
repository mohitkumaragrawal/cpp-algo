#include <iostream>
#include <string>

std::string remove_dups(std::string s) {
  if (s.length() == 0) return "";
  char ch = s[0];
  std::string ans = remove_dups(s.substr(1));
  if (ch == ans[0]) return ans;
  return ch + ans;
}

int main() { std::cout << remove_dups("traffic") << std::endl; }