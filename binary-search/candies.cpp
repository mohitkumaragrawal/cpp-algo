#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;

  int freq[26];
  for (int i = 0; i < 26; ++i) freq[i] = 0;

  for (auto ch : s) {
    freq[ch - 'a']++;
  }

  bool foundOdd = false;

  int max_length = 0;
  for (int i = 0; i < 26; ++i) {
    if (freq[i] & 1) {
      foundOdd = true;
      max_length += (freq[i] - 1);
    } else {
      max_length += freq[i];
    }
  }

  if (foundOdd) max_length += 1;

  int T;
  cin >> T;

  while (T--) {
    int q;
    cin >> q;

    if (q > max_length) {
      cout << -1 << endl;
    } else {
      cout << q << endl;
    }
  }
}