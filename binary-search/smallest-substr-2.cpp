#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  string str;
  cin >> str;
  int N = str.size();

  int freq[26] = {0};
  for (char ch : str) freq[ch - 'a']++;

  int distinct = 0;
  for (int i = 0; i < 26; ++i) {
    if (freq[i] > 0) distinct++;
  }

  int ans = str.size();
  int l = 0, r = 0;

  int window[26] = {0};
  int d = 0;

  int len = N;

  for (r = 0; r < N; ++r) {
    int idx = str[r] - 'a';
    window[idx]++;
    if (window[idx] == 1) d++;

    if (d != distinct) continue;

    while (window[str[l] - 'a'] > 1) {
      window[str[l] - 'a']--;
      l++;
    }

    len = min(len, (r - l + 1));
  }

  cout << len << endl;
}