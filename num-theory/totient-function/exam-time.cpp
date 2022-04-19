#include <array>
#include <iostream>
#define MAXN 1000000

using namespace std;

array<int, MAXN + 1> etf;

void init_etf() {
  for (int i = 0; i < etf.size(); ++i) etf[i] = i;

  for (int i = 2; i < etf.size(); ++i) {
    if (etf[i] != i) continue;
    for (int j = i; j < etf.size(); j += i) {
      etf[j] = (etf[j] / i) * (i - 1);
    }
  }
}

int main() {
  init_etf();

  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    cout << etf[x] << endl;
  }
}