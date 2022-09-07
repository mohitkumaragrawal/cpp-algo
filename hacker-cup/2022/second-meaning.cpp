#include <bits/stdc++.h>
using namespace std;

string number_to_encoding(int num) {
  string result;

  for (int i = 0; i <= 6; ++i) {
    bool has = num & (1 << i);
    result.push_back(has ? '-' : '.');
  }
  return result;
}

int main() {
  freopen("second-meaning.txt", "r", stdin);
  int T;
  cin >> T;

  for (int test = 1; test <= T; ++test) {
    int N;
    cin >> N;

    string c1;
    cin >> c1;

    string prefix = (c1[0] == '.') ? "-" : ".";
    cout << "Case #" << test << ":" << endl;

    for (int i = 1; i <= N - 1; ++i) {
      string code = prefix + number_to_encoding(i);
      cout << code << endl;
    }
  }
}