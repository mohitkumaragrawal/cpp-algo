#include <iostream>
#include <map>
using namespace std;

int sieve[100001];

void init_sieve() {
  for (int i = 0; i < 100001; ++i)
    sieve[i] = i;

  for (int i = 2; i * i < 100001; ++i) {
    for (int j = i * i; j < 100001; j += i) {
      if (sieve[j] == j)
        sieve[j] = i;
    }
  }
}

long long getpath(int num) {
  long long ans = 0;

  while (num > 1) {
    ans += sieve[num];
    num /= sieve[num];
  }
  return ans;
}

int gcd(int a, int b) {
  if (b == 0)
    return a;

  return gcd(b, b % a);
}

int main() {
  init_sieve();
  int T;
  cin >> T;

  while (T--) {
    int N, Q;
    cin >> N >> Q;

    while (Q--) {
      int u, v;
      cin >> u >> v;

      if (v < u)
        swap(u, v);
      if (v % u == 0) {
        cout << getpath(v / u) << endl;
      } else {
        int g = gcd(u, v);
        int ans = getpath(u / g) + getpath(v / g);
        cout << ans << endl;
      }
    }
  }
}
