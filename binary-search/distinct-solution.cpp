#include <algorithm>
#include <iostream>

using namespace std;
using ull = unsigned long long;

int calculated_solutions(int t1, int t2, int time) {
  return (time / t1) + (time / t2);
}

bool is_both_finished(int N, int t1, int t2, int time) {
  int time1 = (time / t1) * t1;
  int time2 = (time / t2) * t2;

  if (calculated_solutions(t1, t2, time1) < N ||
      calculated_solutions(t1, t2, time2) < N)
    return false;
  return true;
}

// find the time when both stopped;
ull find_time(int N, int t1, int t2) {
  ull hightime = 2;
  ull lowtime = 1;

  while (!is_both_finished(N, t1, t2, hightime)) {
    lowtime = hightime;
    hightime *= 2;
  }
  ull time = hightime;

  while (true) {
    if (lowtime > hightime) break;

    ull mid = lowtime + (hightime - lowtime) / 2;

    if (is_both_finished(N, t1, t2, mid)) {
      hightime = mid - 1;
      time = mid;
    } else {
      lowtime = mid + 1;
    }
  }
  return time;
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