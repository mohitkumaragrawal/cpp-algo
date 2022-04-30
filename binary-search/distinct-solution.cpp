#include <algorithm>
#include <iostream>

using namespace std;
using ull = unsigned long long;

#define endl '\n'

// find the time when both stopped;
ull find_time(int N, int t1, int t2) {
  ull low = 1, high = 1e+9, x = 1e+9, y;

  while (true) {
    if (low > high) break;

    auto mid = low + (high - low) / 2;
    auto bob = (mid * t1) / t2;

    if (mid + bob >= N) {
      x = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  low = 1;
  high = 1e+9;
  y = high;
  while (true) {
    if (low > high) break;
    auto mid = low + (high - low) / 2;
    auto alice = (mid * t2) / t1;

    if (mid + alice >= N) {
      y = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return max(x * t1, y * t2);
}

void solve(int N, int t1, int t2) {
  ull time = find_time(N, t1, t2);

  ull solutions = min((int)(time / t1 + time / t2), N + 1);
  cout << solutions << " " << time << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int N, t1, t2;
    cin >> N >> t1 >> t2;
    solve(N, t1, t2);
  }
}