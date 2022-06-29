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

long long binexp(int base, int pw) {
  long long result = 1;

  while (pw > 0) {
    if (pw & 1) {
      pw--;
      result *= base;
    } else {
      base *= base;
      pw /= 2;
    }
  }
  return result;
}

long long divisorSum(int num) {
  map<int, int> mp;

  while (num > 1) {
    mp[sieve[num]]++;
    num /= sieve[num];
  }

  long long ans = 1;
  for (auto pr : mp) {
    long long factor = (binexp(pr.first, pr.second + 1) - 1) / (pr.first - 1);
    ans *= factor;
  }
  return ans;
}

int gcd(int a, int b) {
  if (b == 0)
    return a;

  return gcd(b, b % a);
}

int main() {
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
        cout << v / u << endl;
      } else {
        int g = gcd(u, v);
        cout << (u + v) / g << endl;
      }
    }
  }
}
