
/*

Clearly, if all the input numbers had a different length,
the problem would have a trivial solution:
 "Just iterate over the input numbers in decreasing
  order by length, choosing each number if and only
  if XORing it with the maximum so far increases the
  maximum, i.e, if and only if its leading bit is not
  set in the current maximum;"

Now assume that we've already considered all the input numbers
long then k bits, and determined the maximum value the bits
higher than k can have in their XOR, and we're now considering
whether to XOR a k-bit number, which, by assumption above, is
the only k-bit number in the input - into the maximum or not.
We cannot change the bits above the k-th bit by doing so, but
we can always ensure that the k-th bit in the result is set,
by XORing the current input number into the result if and only
if the k-thh bit of the rsult so far is not yet set. Further,
ensuring that the k-th bit is set is clearly more important
than anything that may happen to the lower bit as a side effect,
so we may ignore those bits for now.

The tricky part is when the input may contain multiple numbers
with the same length, since then it's not obvious which of them
we should choose to include in the XOR. What we'd like to do is
reduce the input list into an equivalent form that doesn't
contain more than one number of the same length;

*/

// C++ program to find
// maximum XOR subset
#include <bits/stdc++.h>
using namespace std;

// Number of bits to
// represent int
#define INT_BITS 32

// Function to return
// maximum XOR subset
// in set[]
int maxSubsetXOR(int set[], int n) {
  // Initialize index of
  // chosen elements
  int index = 0;

  // Traverse through all
  // bits of integer
  // starting from the most
  // significant bit (MSB)
  for (int i = INT_BITS - 1; i >= 0; i--) {
    // Initialize index of
    // maximum element and
    // the maximum element
    int maxInd = index;
    int maxEle = INT_MIN;
    for (int j = index; j < n; j++) {
      // If i'th bit of set[j]
      // is set and set[j] is
      // greater than max so far.
      if ((set[j] & (1 << i)) != 0 && set[j] > maxEle)
        maxEle = set[j], maxInd = j;
    }

    // If there was no
    // element with i'th
    // bit set, move to
    // smaller i
    if (maxEle == INT_MIN) continue;

    // Put maximum element
    // with i'th bit set
    // at index 'index'
    swap(set[index], set[maxInd]);

    for (int j = 0; j < n; ++j) cout << set[j] << " \n"[j == n - 1];
    // Update maxInd and
    // increment index
    maxInd = index;

    // Do XOR of set[maxIndex]
    // with all numbers having
    // i'th bit as set.
    for (int j = 0; j < n; j++) {
      // XOR set[maxInd] those
      // numbers which have the
      // i'th bit set
      if (j != maxInd && (set[j] & (1 << i)) != 0)
        set[j] = set[j] ^ set[maxInd];
    }

    for (int j = 0; j < n; ++j) cout << set[j] << " \n"[j == n - 1];

    cout << "\n";

    // Increment index of
    // chosen elements
    index++;
  }

  // Final result is
  // XOR of all elements
  int res = 0;
  for (int i = 0; i < n; i++) res ^= set[i];
  return res;
}

// Driver program
int main() {
  // int set[] = {1, 2, 4, 7, 7};
  // int n = sizeof(set) / sizeof(set[0]);
  //
  int n;
  cin >> n;

  int set[n];
  for (int i = 0; i < n; ++i) cin >> set[i];

  cout << maxSubsetXOR(set, n);
  return 0;
}
