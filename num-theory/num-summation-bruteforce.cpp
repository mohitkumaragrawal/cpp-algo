#include <iostream>
#include <map>
#define mod 1000000007

using namespace std;
using ull = uint64_t;

ull gcd(ull a, ull b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

map<ull, ull> primefact(ull n)
{
  map<ull, ull> result;

  for (ull i = 2; i * i <= n; ++i)
  {
    while (n % i == 0)
    {
      n /= i;
      result[i]++;
    }
  }

  if (n > 1)
    result[n]++;
  return result;
}

ull binexp(ull base, ull pow)
{
  ull result = 1;
  while (pow > 0)
  {
    if (pow & 1)
    {
      pow--;
      result = (result * base) % mod;
    }
    else
    {
      pow /= 2;
      base = (base * base) % mod;
    }
  }
  return result;
}

ull f(ull x, ull y)
{
  ull g = gcd(x, y);
  auto pf = primefact(g);

  ull result = 1;
  for (auto pr : pf)
  {
    ull tmp = 1;
    for (ull i = 1; i <= pr.second; ++i)
    {
      tmp = (tmp + binexp(pr.first, i)) % mod;
    }
    result = (result * tmp) % mod;
  }
  return result;
}
int main()
{
  ull N;
  cin >> N;

  ull result = 0;
  for (ull i = 1; i <= N; ++i)
  {
    for (ull j = i; j <= N; ++j)
    {
      result = (result + f(i, j));
    }
  }
  cout << result << endl;
}