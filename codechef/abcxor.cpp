#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		unsigned long long int K;
		cin >> K; // ignored

		unsigned long long int pow2n = 1 << N;
		unsigned long long int ans = (pow2n * pow2n) - 3 * (pow2n) + 2;
		cout << ans << endl;
	}
}
