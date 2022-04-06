// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/archery-1/

#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, (a % b));
}

ll lcm(vector<ll>& vi) {
  ll ans = vi[0];

  for (ll i = 1; i < vi.size(); ++i) {
    // ans = lcm of ans vi[i]
    ans = (ans * vi[i]) / gcd(ans, vi[i]);
  }
  return ans;
}

int main() {
  ll T;
  cin >> T;
  while (T--) {
    ll N;
    cin >> N;
    vector<ll> v(N);
    for (auto& i : v) cin >> i;

    cout << lcm(v) << endl;
  }
}