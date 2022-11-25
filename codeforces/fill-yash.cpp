#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9;

int vrr[505][505];
void solve(int brr[], int n) {
  for (int k = 1; k <= n; k++) {
    vrr[k][k] = brr[k];
    int j = k;
    int i = k;
    int x = brr[k];
    x--;
    while (x != 0) {
      while (j > 1 && vrr[i][j - 1] == 0 && x != 0) {
        j -= 1;
        vrr[i][j] = brr[k];
        x--;
      }
      while (i < n && vrr[i + 1][j] == 0 && x != 0) {
        i += 1;
        vrr[i][j] = brr[k];
        x--;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  scanf("%d", &n);
  int arr[n + 5];
  unordered_set<int> s;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    s.insert(arr[i]);
  }
  if (s.size() != n) {
    cout << "-1\n";
    return 0;
  }
  memset(vrr, 0, sizeof(vrr));
  solve(arr, n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      printf("%d ", vrr[i][j]);
    }
    printf("\n");
  }
}
