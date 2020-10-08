#include<iostream>

using namespace std;
long long int dp[1001][1001];

void dynamic(int n, int m) {
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][1] = 1;
	}
	for (int i = 2; i <= m; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j-1] + dp[i - 1][j - 1])%1000000007;
		}
	}
}
int main(void) {
	int n, m;
	cin >> n >> m;
	dynamic(n, m);
	cout << dp[n][m] << endl;
	return 0;
}
