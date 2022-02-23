#include <string>
#include <iostream>
#include <map>
using namespace std;

int anagram(const string& str) {
  if (str.size() % 2 == 1) return -1;
  int half = str.size() / 2;

  map<char, int> mp1;
  map<char, int> mp2;

  for (int i = 0; i < half; ++i) {
    mp1[str[i]]++;
  }

  for (int i = half; i < str.size(); ++i) {
    mp2[str[i]]++;
  }

  for (auto& pair: mp1) {
    pair.second = max(0, pair.second - mp2[pair.first]);
  }

  int ans = 0;
  for (auto pair: mp1) {
    ans += pair.second;
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    auto result = anagram(s);
    cout << result << endl;
  }
}