#include <iostream>
#include <vector>
using namespace std;

const long monk_quotient = 1000000007ll;

long gcd(long a, long b) {
  if (b == 0) return a;
  return gcd(b, (a%b));
}
long confused_monk(vector<long>& arr) {
  if (arr.empty()) return 0l;
  long gx = arr[0];
  for (int i = 1; i < arr.size(); ++i) {
    gx = gcd(gx, arr[i]);
  }

  long fx = arr[0];
  for (int i = 1; i < arr.size(); ++i) {
    fx *= arr[i];
    fx %= monk_quotient;
  }

  long result = 1;
  while (gx > 0) {
    if (gx & 1) {
      gx--;
      result *= fx;
      result %= monk_quotient;
    } else {
      gx /= 2;
      fx *= fx;
      fx %= monk_quotient;
    }
  }
  return result;
}

int main() {
  long n; cin >> n;
  vector<long> arr(n);
  for (auto& el: arr) cin >> el;
  cout << confused_monk(arr) << endl;
}