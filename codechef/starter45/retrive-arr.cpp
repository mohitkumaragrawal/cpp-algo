#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  using ll = long long;
  while (T--) {
    int N;
    cin >> N;

    vector<ll> arr(N);
    for (auto &i : arr)
      cin >> i;

    ll sum = 0;
    for (auto i : arr)
      sum += i;

    auto T = sum / (1 + N);

    for (auto i : arr)
      cout << i - T << " ";
    cout << endl;
  }
}
