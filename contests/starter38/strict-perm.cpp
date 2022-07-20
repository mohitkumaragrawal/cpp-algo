#include <bits/stdc++.h>
using namespace std;

int inf = 1e+8;
#define endl '\n'

void solve(int N, int M) {
  vector<int> arr(N+1, -1);
  vector<int> cond(N + 1, inf);
  vector<int> idx(N+1);
  for (int i = 1; i <= N; ++i) {
    idx[i] = i;
  }

  while (M--) {
    int x, y;
    cin >> x >> y;

    cond[x] = y; 
  }

  int el = N;
  while (el >= 1) {
    if (cond[el] >= N) {
      int pos = N;
      pos = idx[pos];
      if (pos <= 0) goto no_solution;
      while (arr[pos] != -1) {
        pos--;

        if (pos <= 0) {
          goto no_solution;
        }
      }
      arr[pos] = el;
      el--;
      idx[N] = pos-1;
      continue;
    } 

    int npos = cond[el];
    npos = idx[npos];
    if (npos <= 0) goto no_solution;
    while (arr[npos] != -1) {
      npos--;

      if (npos <= 0) {
        goto no_solution;
      }
    }

    arr[npos] = el;
    idx[cond[el]] = npos - 1;
    el--;
  }
  
  for (int i = 1; i <= N; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return;
  
  no_solution:
  cout << -1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    int N, M;
    cin >> N >> M;

    solve(N, M);
  }
}