#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int distinct_chars(string& s, int l) {
  int freq[26];
  for (int i = 0; i < 26; ++i) freq[i] = 0;

  for (int i = 0; i < l; ++i) {
    freq[s[i] - 'a']++;
  }

  int distinct = 0;
  for (int i = 0; i < 26; ++i) {
    if (freq[i] > 0) distinct++;
  }

  if (distinct == l) return l;
  int ans = distinct;

  for (int i = l; i < s.size(); ++i) {
    freq[s[i - l] - 'a']--;
    if (freq[s[i - l] - 'a'] == 0) distinct--;

    freq[s[i] - 'a']++;
    if (freq[s[i] - 'a'] == 1) distinct++;

    ans = max(ans, distinct);
  }

  return ans;
}

int main() {
  string s;
  cin >> s;

  int freq[26];
  for (int i = 0; i < 26; ++i) freq[i] = 0;

  for (auto ch : s) freq[ch - 'a']++;

  int distinct = 0;
  for (int i = 0; i < 26; ++i) {
    if (freq[i] > 0) distinct++;
  }

  int low = distinct;
  int high = s.size();

  int ans = s.size();

  while (true) {
    if (low > high) break;
    int mid = low + (high - low) / 2;

    int dc = distinct_chars(s, mid);

    if (dc < distinct) {
      low = mid + 1;
    } else {
      ans = mid;
      high = mid - 1;
    }
  }

  cout << ans << endl;
}