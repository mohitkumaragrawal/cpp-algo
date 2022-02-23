#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<bool> weighted_uniform_string(const string& str, const vector<int>& queries) {
  int freq[26];
  for (int i = 0; i < 26; ++i) freq[i] = 0;
  char last_char = '0';
  int size = 0;
  
  for (char ch: str) {
    if (size == 0) {
      last_char = ch;
      size++;
      continue;
    } 
    if (last_char == ch) {
      size++;
    } else {
      int t = last_char - 'a';
      freq[t] = max(freq[t], size);
      size = 1;
      last_char = ch;
    }
  }
  int t = last_char - 'a';
  freq[t] = max(freq[t], size);
  vector<bool> ans;

  for (int q: queries) {
    bool result = false;
    for (int i = 0; i < 26; ++i) {
      if (q % (i+1) == 0) {
        if ((q/(i+1)) <= freq[i]) {
          result = true;
          break;
        }
      }
    }
    ans.push_back(result);
  }

  return ans;
}

int main() {
  string str;
  cin >> str;

  int q;
  cin >> q;

  vector<int> queries(q);
  for (int& i: queries) cin >> i;
  
  auto result = weighted_uniform_string(str, queries);
  for (auto r: result) {
    if (r) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}