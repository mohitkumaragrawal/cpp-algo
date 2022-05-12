#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for (int& x : A) cin >> x;
    for (int& x : B) cin >> x;

    map<pair<int, int>, int> mp;
    long long count = 0;

    for (int i = 0; i < N; ++i) {
      count += mp[{B[i], A[i]}];

      mp[{A[i], B[i]}]++;
    }

    cout << count << endl;
  }
}