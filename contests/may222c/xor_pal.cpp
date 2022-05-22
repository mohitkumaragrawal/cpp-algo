#include <iostream>
#include <string>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    string s;
    cin >> s;

    int mis = 0, l = 0, r = N - 1;
    while (r > l) {
      if (s[l] != s[r]) {
        mis++;
      }

      l++;
      r--;
    }

    int ans = mis / 2;
    if (mis & 1) ans++;

    cout << ans << endl;
  }
}