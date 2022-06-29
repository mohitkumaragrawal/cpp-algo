#include <iostream>
#include <string>

using namespace std;

using ull = unsigned long long;

#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;

    bool has_a = false;

    for (char ch : t) {
      if (ch == 'a') {
        has_a = true;
        break;
      }
    }
    if (has_a) {
      if (t.size() > 1) {
        cout << -1 << endl;
      } else {
        cout << 1 << endl;
      }
    } else {
      ull ans = 1;
      for (int i = 0; i < s.size(); ++i) {
        ans *= 2;
      }
      cout << ans << endl;
    }
  }
}
