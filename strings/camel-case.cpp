#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string s;
  getline(cin, s);
  cout << 1 + count_if(s.begin(), s.end(), ::isupper) << endl;
}