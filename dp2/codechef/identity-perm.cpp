#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ll n, k;
  cin >> n >> k;

  ll ans = 0;

  // c denotes the n choose r, initilly r is 0, so c is 1;
  // d is dearrangements of r elements where r is initially 0;
  ll c = 1, d = 1;
  ans += c * d;

  for (ll i = 1; i <= k; ++i)
  {
    c *= (n - i + 1);
    c /= i;

    d = i * d;
    if (i % 2 == 0)
    {
      d += 1;
    }
    else
    {
      d -= 1;
    }

    ans += c * d;
  }
  cout << ans << endl;
}