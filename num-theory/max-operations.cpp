#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ull = uint64_t;

struct xor_op {
  ull operator()(ull a, ull b) {
    return a ^ b;
  }
};

struct xnor_op {
  ull operator()(ull a, ull b) {
    if (a < b)
        swap(a, b);
 
    if (a == 0 && b == 0)
        return 1;
 
    ull a_rem = 0; // for last bit of a
    ull b_rem = 0; // for last bit of b
 
    ull count = 0;
 
    ull xnornum = 0;
 
    while (a)
    {
        // get last bit of a
        a_rem = a & 1;
 
        // get last bit of b
        b_rem = b & 1;
 
        // Check if current two
        // bits are same
        if (a_rem == b_rem)       
            xnornum |= (1 << count);
         
        // counter for count bit
        count++;
        a = a >> 1;
        b = b >> 1;
    }
    return xnornum;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    ull a, b, n;
    cin >> a >> b >> n;

    n = n % 3;
    ull x, e;

    switch(n) {
      case 0:
        x = xor_op()(a, b);
        e = xnor_op()(a, b);
        break;
      case 1:
        x = a;
        e = a;
        break;
      case 2:
        x = b;
        e = b;
    }
    cout << max(x, e) << endl;
  }
}