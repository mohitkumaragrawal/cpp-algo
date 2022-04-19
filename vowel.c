#include <stdio.h>

int getLastDigit(int num) { return num % 10; }

int getFirstDigit(int num) {
  int ans = num % 10;
  num /= 10;

  while (num > 0) {
    ans = num % 10;
    num /= 10;
  }

  return ans;
}

int main() {
  for (int i = 1; i <= 1000; ++i) {
    if (getFirstDigit(i) == getLastDigit(i)) {
      printf("%d\n", i);
    }
  }
}