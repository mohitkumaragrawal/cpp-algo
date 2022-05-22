#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vc;

  int n;
  cin >> n;

  vc.resize(n);

  for (auto& x : vc) cin >> x;

  for (auto x : vc) cout << x << ", ";
}