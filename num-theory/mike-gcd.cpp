#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define MAXN 100000

array<bool, MAXN + 1> sieve;
void init_sieve() {
  sieve[0] = false;
  sieve[1] = false;
  for (int i = 2; i < sieve.size(); ++i) sieve[i] = true;

  for (int i = 2; i * i < sieve.size(); ++i) {
    if (!sieve[i]) continue;
    for (int j = i * i; j < sieve.size(); j += i) sieve[j] = false;
  }
}

int main() {
  freopen("mike-gcd.txt", "r", stdin);
  init_sieve();

  int N;
  cin >> N;

  vector<int> arr(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
  }

  vector<vector<int>> mat;

  for (int i = 2; i * i <= MAXN; ++i) {
    if (!sieve[i]) continue;
    vector<int> v;

    for (int j = 1; j <= N; ++j) {
      if (arr[j] % i == 0) v.push_back(j);
    }

    if (v.size() >= 2) mat.push_back(v);
  }

  vector<int> ans(N + 1, -1);

  for (auto& v : mat) {
    for (int i = 1; i < v.size(); ++i) {
      int a = v[i];
      int b = v[i - 1];

      if (ans[a] == -1) {
        ans[a] = b;
      } else {
        int original_distance = abs(ans[a] - a);
        int new_distance = abs(b - a);

        if (new_distance < original_distance) {
          ans[a] = b;
        }
        if (new_distance == original_distance) {
          ans[a] = min(ans[a], b);
        }
      }

      if (ans[b] == -1) {
        ans[b] = a;
      } else {
        int original_distance = abs(ans[b] - b);
        int new_distance = abs(a - b);

        if (new_distance < original_distance) {
          ans[b] = a;
        }
        if (new_distance == original_distance) {
          ans[b] = min(ans[b], a);
        }
      }
    }
  }

  for (int i = 1; i <= N; ++i) {
    cout << ans[i] << " ";
  }
}