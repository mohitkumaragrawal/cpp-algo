#include <array>
#include <iostream>
#define mod 1000000007

using namespace std;
using ll = long long;

ll pow2[1000001];
ll pow3[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pow2[0] = pow3[0] = 1;
  for (int i = 1; i < 1000001; ++i) {
    pow2[i] = (pow2[i - 1] * 2) % mod;
    pow3[i] = (pow3[i - 1] * 3) % mod;
  }

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    auto pow4 = (pow2[N] * pow2[N]) % mod;

    auto ans = (pow4 - 2 * pow3[N] + pow2[N]) % mod;
    while (ans < 0) ans += mod;
    cout << ans << '\n';
  }
}