#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

std::string reverse(const std::string& str) {
  if (str.size() == 1) return str;

  return str[str.size() - 1] + reverse(str.substr(0, str.size() - 1));
}

void replace_str(std::string& str, const std::string& ostr,
                 const std::string& nstr) {
  auto pos = str.find(ostr);

  while (pos != std::string::npos) {
    str.replace(pos, ostr.size(), nstr);
    pos = str.find(ostr);
  }
}

void replace_pi(std::string& str, int pos = 0) {
  if (pos >= str.size() - 1) return;

  const std::string pivalue = "3.14";

  if (str[pos] == 'p' && str[pos + 1] == 'i') {
    str.replace(pos, 2, pivalue);
    pos += pivalue.size() - 1;
  }

  replace_pi(str, pos + 1);
}

int main() {
  std::string s1 = "heLLo WorLd";

  std::transform(s1.begin(), s1.end(), std::ostream_iterator<char>(std::cout),
                 ::toupper);
  std::cout << std::endl;

  std::string s2;
  std::copy(s1.rbegin(), s1.rend(), std::back_inserter(s2));
  std::cout << s2 << std::endl;

  std::reverse(s1.begin(), s1.end());
  std::cout << s1 << std::endl;

  std::cout << reverse(s1) << std::endl;

  std::string pistring =
      "pi is greater than 3 but pi is less the 4";
  replace_pi(pistring);

  std::cout << pistring << std::endl;
}