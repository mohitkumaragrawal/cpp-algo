#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string remove_ith_char(std::string str, int i) {
  return str.replace(i, 1, "");
}

std::vector<std::string> permutations(const std::string& str) {
  if (str.size() == 1) {
    return std::vector<std::string>{str};
  }

  std::vector<std::string> result;

  for (int i = 0; i < str.size(); ++i) {
    // all the permuations without that character;
    auto perms = permutations(remove_ith_char(str, i));

    for (auto p : perms) {
      result.push_back(str[i] + p);
    }
  }

  return result;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
  char comma[3] = {'\0', ' ', '\0'};

  out.put('[');
  for (auto el : vec) {
    out << comma << el;
    comma[0] = ',';
  }
  out.put(']');
  return out;
}

int main() { std::cout << permutations("ABCD") << std::endl; }