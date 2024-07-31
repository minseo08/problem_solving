#include<iostream>
#define MAX 1000000000
using namespace std;
long long dp[1<<10][101][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
    cin >> n;

	if (n <= 9) {
		cout << 0 << "\n";
		return 0;
	}

	for (int i = 1; i <= 9; i++) {
		dp[1<<i][1][i] = 1;
	}
	for (int i = 2; i <= n; i++) { //숫자 개수!
		for (int k = 0; k <= 9; k++) { //마지막 수의 번호!
			for (int bit = 0; bit < (1 << 10); bit++) { //이전 비트!
				if (k == 0) {
					dp[bit | (1 << k)][i][k] += dp[bit][i - 1][k+1] % MAX;
				}
				else if (k == 9) {
					dp[bit | (1 << k)][i][k] += dp[bit][i - 1][k - 1] % MAX;
				}
				else {
					dp[bit | (1 << k)][i][k] += (dp[bit][i - 1][k + 1] + dp[bit][i - 1][k - 1]) % MAX;
				}
			}
		}
	}

	long long answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer = (answer + dp[(1<<10) - 1][n][i]) % MAX;
	}
	cout << answer;
	return 0;
}