#include <string>
#include <iostream>
#include <set>

using namespace std;

int main() {
  string str;
  getline(cin, str);

  // set<char> s;
  
  // for (char c: str) {
  //   if (isalpha(c)) {
  //     s.insert(tolower(c));
  //   }
  // }

  // if (s.size() == 26) {
  //   cout << "YES";
  // } else {
  //   cout << "NO";
  // }

  bool seen[26];
  for (int i = 0; i < 26; ++i) seen[i] = false;

  for (char c: str) {
    if (isalpha(c)) {
      seen[tolower(c) - 'a'] = true;
    }
  }

  bool pangram = true;
  for (int i = 0; i < 26; ++i) {
    pangram &= seen[i];
  }

  if (pangram) {
    cout << "pangram" << endl;
  } else {
    cout << "no pangram" << endl;
  }
}