#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  map<char, int> mp1, mp2;
  for (auto ch: s1) mp1[ch]++;
  for (auto ch: s2) mp2[ch]++;

  for (auto& pair: mp1) {
    pair.second = max(0, pair.second - mp2[pair.first]);
  }

  int diff = 0;
  for (auto pair: mp1) {
    diff += pair.second;
  }
  
  int cmn = s1.size() - diff;

  int ans = (s1.size() + s2.size()) - 2 * cmn;
  cout << ans << endl;
}