#include <iostream>
#include <vector>

using namespace std;

using Num = unsigned long long;
Num magic = 1000'000'007;
Num A, B;

using Mat = vector<vector<Num>>;
Mat make_mat() {
  return Mat(2, vector<Num>(2, 0));
}

Mat mul(Mat a, Mat b) {
  auto r = make_mat();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        r[i][j] += (a[i][k] * b[k][j])%magic;
      }
    }
  }
  return r;
}

Mat mexp(Mat base, Num pow) {
  auto m = make_mat(); m[0][0] = 1; m[1][1] = 1;
  while (pow > 0) {
    if (pow & 1) {
      pow--;
      m = mul(m, base);
    } else {
      base = mul(base, base);
      pow /= 2;
    }
  }
  return m;
}


void display_matrix(const Mat& m) {
  for (int i = 0; i < m.size(); ++i) {
    for (int j = 0; j < m[i].size(); ++j) {
      cout << m[i][j] << " ";
    } cout << endl;
  }
}

Num fib(Num n) {
  if (n == 0) return A;
  if (n == 1) return B;

  Mat m = make_mat();
  m[0][1] = 1; m[1][0] = 1; m[1][1] = 1;
  
  m = mexp(m, n-1);
  Num result = (A * m[0][1] + B * m[1][1])%magic;
  return result;
}

int main() {
  int t; cin >> t;
  while (t--) {
    cin >> A >> B;
    Num n;
    cin >> n;
    auto result = fib(n);
    cout << result << endl;
  }

}