#include <iostream>
#include <string>
using namespace std;

#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    string s;
    cin >> s;

    int ans = (s[0] - 'a') * 25 + 1 + (s[1] - 'a');
    if (s[1] > s[0]) ans--;
    cout << ans << endl;
  }
}