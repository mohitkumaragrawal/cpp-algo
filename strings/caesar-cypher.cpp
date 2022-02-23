#include <string>
#include <map>
#include <iostream>

using namespace std;

string caesar_cypher(const string& str, int k) {
  string ans;

  map<char, char> mp;
  char key, val;
  for (int i = 0; i < 26; ++i) {
    int j = (i + k) % 26;
    key = (char) ('a' + i);
    val = (char) ('a' + j);
    mp[key] = val;
    key = (char) ('A' + i);
    val = (char) ('A' + j);
    mp[key] = val;
  }

  for (char ch: str) {
    if (isalpha(ch)) {
      ans.push_back(mp[ch]);
    } else {
      ans.push_back(ch);
    }
  }
  return ans;
}

int main() {
  int n, k;
  string s;
  cin >> n >> s >> k;

  cout << caesar_cypher(s, k) << endl;
}