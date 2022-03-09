#include <iostream>
using namespace std;

int gcd_extended(int a, int b, int& x, int& y) { 
  if (b == 0) {
    x = 1;
    y = 0; // any value will do;
    return a;
  }

  int x1, y1;
  int g = gcd_extended(b, (a % b), x1, y1);
  x = y1;
  y = x1 - (a/b) * y1;
  return g;
}

int main() {
  while (true) {
    int a, b;
    cin >> a >> b;
    int x, y;
    int g = gcd_extended(a,b,x,y);
    cout << a << "*" << x << " + " << b << "*" << y << " = " << g << endl;
  }
}