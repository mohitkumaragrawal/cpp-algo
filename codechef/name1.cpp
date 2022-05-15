#include <iostream>
#include <string>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    string a, b;
    cin >> a >> b;

    int freq[26];
    for (int i = 0; i < 26; ++i) freq[i] = 0;

    for (auto ch : a) freq[ch - 'a']++;
    for (auto ch : b) freq[ch - 'a']++;

    int kids;
    cin >> kids;

    while (kids--) {
      string kidName;
      cin >> kidName;

      for (auto ch : kidName) freq[ch - 'a']--;
    }

    bool flag = false;
    for (int i = 0; i < 26; ++i) {
      if (freq[i] < 0) {
        flag = true;
        break;
      }
    }
    if (flag) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}