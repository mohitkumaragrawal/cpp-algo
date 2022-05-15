#include <iostream>
using namespace std;
using ll = int64_t;

#define mod 1000000007

ll binexp(ll base, ll p) {
  ll res = 1;

  while (p > 0) {
    if (p & 1) {
      p--;
      res = (res * base) % mod;
    } else {
      p /= 2;
      base = (base * base) % mod;
    }
  }

  return res;
}

int main() {
  ll T;
  cin >> T;
  while (T--) {
    ll N;
    cin >> N;

    cout << binexp(2, N - 1) << endl;
  }
}