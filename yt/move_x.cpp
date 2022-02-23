#include <iostream>
#include <string>

std::string move_x(const std::string& s) {
  if (s.size() == 0) return s;

  if (s[0] == 'x') {
    return move_x(s.substr(1)) + 'x';
  }

  return s[0] + move_x(s.substr(1));
}

int main() { std::cout << move_x("hellxx nox whax xender") << std::endl; }