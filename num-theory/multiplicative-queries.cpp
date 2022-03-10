#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
#define mod 1000000007
 
using ull = uint64_t;
 
ull cal_product(vector<ull>& a, vector<ull>& func, ull l, ull r, ull c) {
  map<ull, int> cnt;
  for (int i = l; i <= r; ++i) {
    cnt[a[i]]++;
  }
  ull prod = 1;
  for (ull i = 1; i <= c; ++i) {
    prod = (prod * func[cnt[i]]) % mod;
  }
  return prod;
}
 
int main() {
  ull n, c, q;
  cin >> n >> c >> q;
  vector<ull> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<ull> func(n+1);
  for (int i = 0; i < n+1; ++i) {
    cin >> func[i];
  }
 
  auto result = 1;
  
  while (q--) {
    ull l, r;
    cin >> l >> r;
    result = (result * cal_product(a, func, l, r, c)) % mod;
  }
  cout << result  << endl;
}