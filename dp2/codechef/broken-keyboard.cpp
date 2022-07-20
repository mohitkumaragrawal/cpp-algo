#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int N, k;
  string s;

  cin >> N >> k >> s;
  bool typeable[26] = {false};
  for (int _ = 1 ; _ <= k; ++_) {
    char ch;
    cin >> ch;
    typeable[ch - 'a'] = true;
  }

  ll ans = 0;
  vector<ll> f(N+1);
  f[0] = 0;

  for (int i = 0; i < N; ++i) {
    if (typeable[s[i] - 'a']) {
      f[i+1] = f[i] + 1;
    } else {
      f[i+1] = 0;
    }
    ans += f[i+1];
  }
  cout << ans << endl;
}

// int main() {
//   int N, k;
  
//   string s;
//   cin >> N >> k >> s;

//   set<char> keys;
//   for (int _ = 1; _ <= k; ++_) {
//     char ch; cin >> ch;
//     keys.insert(ch);
//   }

//   vector<pair<int, int>> indices;
//   int start_idx = -1;
//   for (int i = 0; i < N; ++i) {
//     if (keys.find(s[i]) != keys.end()) {
//       if (start_idx == -1) start_idx = i;
//       continue;
//     }
//     if (start_idx != -1) {
//       indices.push_back(make_pair(start_idx, i-1));
//       start_idx = -1;
//     }
//   }

//   if (start_idx != -1) {
//     indices.push_back(make_pair(start_idx, N-1));
//   }

//   long ans = 0;
//   for (auto pr: indices) {
//     long len = pr.second - pr.first + 1;
//     ans += (len * (len + 1)) / 2;
//   }
//   cout << ans << endl;
// }