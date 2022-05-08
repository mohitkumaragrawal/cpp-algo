#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const double Epsilon = 1e-9;

double calculateRatioSum(vector<double>& A, vector<double>& B, double r) {
  double sum = 0;
  for (int i = 0; i < A.size(); ++i) {
    double ratio = A[i] / (B[i] + r);
    sum += ratio;
  }
  return sum;
}

int main() {
  freopen("tie-breaker.txt", "r", stdin);
  int N, col;
  cin >> N >> col;

  vector<double> A, B;
  for (int i = 0; i < N; ++i) {
    double ai, bi;
    cin >> ai >> bi;
    A.push_back(ai);
    B.push_back(bi);
  }

  double K;
  cin >> K;

  double minB = B[0];
  for (int i = 1; i < N; ++i) {
    if (B[i] < minB) {
      minB = B[i];
    }
  }
  double maxA = A[0];
  for (int i = 1; i < N; ++i) {
    if (A[i] > maxA) {
      maxA = A[i];
    }
  }

  double minR = -minB;
  double maxR = (N * maxA) / K - minB;

  while (true) {
    double r = (maxR + minR) / 2.0;
    double ratioSum = calculateRatioSum(A, B, r);

    if (abs(ratioSum - K) < Epsilon) break;

    // increasing r will decrease the sum, and decreasing will increase the sum;
    if (ratioSum > K) {
      minR = r;
    } else {
      maxR = r;
    }
  }

  double result = (maxR + minR) / 2.0;
  cout << fixed << setprecision(7) << result << endl;
}