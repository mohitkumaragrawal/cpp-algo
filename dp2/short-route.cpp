#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;

  while (T--) {
    int N, M;
    cin >> N >> M;

    vector<int> A(N + 1);
    vector<int> B(M + 1);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 1; i <= M; ++i) cin >> B[i];

    if (N == 1) {
      cout << 0 << endl;
      continue;
    }

    vector<int> front(N + 1, -1);
    vector<int> back(N + 1, -1);

    for (int i = 1; i <= N; ++i) {
      if (A[i] == 1) {
        front[i] = 0; 
      } else if (A[i] == 2) {
        back[i] = 0;
      }
    }

    for (int i = 2; i <= N; ++i) {
      if (front[i-1] == -1) continue;
      if (front[i] == 0) continue;

      front[i] = 1 + front[i-1];
    }

    for (int i = N-1; i >= 0; --i) {
      if (back[i+1] == -1) continue;
      if (back[i] == 0) continue;

      back[i] = 1 + back[i+1];
    }

    // because each passenger was at city 1 at the very biggining
    front[1] = 0;
    back[1] = 0;

    for (int i = 1; i <= M; ++i) {
      int q = B[i];
      int ans;
      if (front[q] == -1) {
        ans = back[q];
      } else if (back[q] == -1) {
        ans = front[q];
      } else {
        ans = min(front[q], back[q]);
      }

      cout << ans << " ";
    }
    cout << endl;
  }
}
