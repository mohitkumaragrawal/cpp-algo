#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
  vector<int> split_version_string(const string& str) {
    string tmp;
    vector<int> result;

    for (auto ch: str) {
      if (ch == '.') {
        result.push_back(stoi(tmp));
        tmp.clear();
        continue;
      }

      tmp.push_back(ch);
    }
    if (!tmp.empty()) {
      result.push_back(stoi(tmp));
    }
    return result;
  }

  int compare_version_list(const vector<int>& a, const vector<int>& b) {
    if (a.size() < b.size()) {
      return -1 * compare_version_list(b, a);
    }

    for (int idx = 0; idx < a.size(); ++idx) {
      int b_version = (idx > (b.size() - 1)) ? 0: b[idx];
      int a_version = a[idx];

      int cmp = (a_version - b_version);

      if (cmp < 0) {
        return -1;
      } else if (cmp > 0) {
        return 1;
      }      
    }
    return 0;
  }
public:
  int compareVersion(string version1, string version2) {
    auto v1 = split_version_string(version1);
    auto v2 = split_version_string(version2);
  
    return compare_version_list(v1, v2);
  }
};

int main() {
  Solution s;
  int result = s.compareVersion("1.5", "1.3");
  switch (result)
  {
  case 0:
    cout << "Same Version" << endl;
    break;
  
  case 1:
    cout << "left is greater" << endl;
    break;

  case -1:
    cout << "left is smaller" << endl;
    break;
  }
}