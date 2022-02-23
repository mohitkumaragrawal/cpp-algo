#include <algorithm>
#include <string>
#include <iostream>
#include <functional>
using namespace std;

int main() {
  using namespace placeholders;
  
  string s = "Hello world";
  //count 'o';
  int o = count_if(s.begin(), s.end(), bind(equal_to<char>(), 'o', _1));
  cout << o << endl;
}