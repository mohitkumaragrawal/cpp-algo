#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  getline(cin, s);

  int lower_case = 1, upper_case = 1, digit = 1, special_char = 1;
  string special = "!@#$%^&*()-+";

  for (auto el: s) {
    if (islower(el)) lower_case = 0;
    if (isupper(el)) upper_case = 0;
    if (isdigit(el)) digit = 0;
    
    if (s.find(el,0) != string::npos) {
      special_char = 0;
    }
  }

  int ans = lower_case + upper_case + special_char;
  
  if (s.size() + ans < 6) {
    ans = 6- s.size();
  }

  cout << ans << endl;
}