#include <iostream>
#include <string>
using namespace std;

int two_characters(const string& str) {
  bool contains[26];
  for (int i = 0; i < 26; ++i) contains[i] = false;
  for (char ch: str) {
    contains[ch-'a'] = true;
  }

  int max_size = 0;
  for (int i = 0; i < 26; ++i) {
    if (!contains[i]) continue;
    for (int j = i+1; j < 26; ++j) {
      if (!contains[j]) continue;
      string ans;

      bool possible = true;
      for (auto ch: str) {
        if ((ch-'a') == i || (ch-'a')==j) {
          if (ans.empty()) {
            ans.push_back(ch);
            continue;
          }
          if (ans.back() == ch) {
            possible = false;
            break;
          }
          ans.push_back(ch);
        }
      }
      if (!possible) continue;

      max_size = max((int)ans.size(), max_size);
    }
  }
  return max_size;
}

int main() {
  int n; cin >> n;
  string input;
  cin >> input;

  auto result = two_characters(input);
  cout << result << endl;
}