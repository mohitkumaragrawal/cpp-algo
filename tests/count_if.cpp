#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
using namespace std;

int main() {
  using namespace placeholders;
  string s = "Hello world";
  int o = count_if(s.begin(), s.end(), bind(equal_to<char>(), 'o', _1));
  cout << o << endl;
}
