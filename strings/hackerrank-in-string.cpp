#include <iostream>
#include <string>
#include <queue>
using namespace std;

bool hackerrank_in_string(const string& str) {
  queue<char> q;
  string s = "hackerrank";
  for (char c: s) q.push(c);

  for (auto c: str) {
    if (q.front() == c) q.pop();
  }

  return q.empty();
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    if (hackerrank_in_string(s)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}