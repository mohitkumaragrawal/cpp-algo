#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(int* freq, int x) {
  int max_length = 0;

  bool foundOdd = false;
  for (int i = 0; i < 26; ++i) {
    if (freq[i] % 2 == 0) {
      max_length += freq[i];
    } else {
      foundOdd = true;
      max_length += freq[i] - 1;
    }
  }
  if (foundOdd) max_length++;
  return x <= max_length;
}

bool func(string& s, int x, int k) {
  int freq[26];
  for (int i = 0; i < 26; ++i) freq[i] = 0;
  for (int i = 0; i < x; ++i) {
    freq[s[i] - 'a']++;
  }

  if (check(freq, k)) {
    return true;
  }

  for (int i = x; i < s.size(); ++i) {
    freq[s[i] - 'a']++;
    freq[s[i - x] - 'a']--;

    if (check(freq, k)) return true;
  }
  return false;
}

#define endl '\n'
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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
      int low = q;
      int high = s.size();
      int ans = -1;

      while (true) {
        if (low > high) break;

        int mid = low + (high - low) / 2;
        if (func(s, mid, q)) {
          ans = mid;
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      cout << ans << endl;
    }
  }
}