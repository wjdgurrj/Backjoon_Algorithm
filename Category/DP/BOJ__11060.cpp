#include<iostream>
#include<algorithm>

using namespace std;

int bridge[1001];
int dp[1001];
int jump(int n) {
	
	for (int i = 1; i <= n; i++) {
		dp[i] = 10000;
	}
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		int a = bridge[i];
		for (int j = 1; j <= a; j++) {
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	if (dp[n] == 10000) {
		return -1;
	}
	return dp[n];
}

int main(void) {
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) {
			cin >> bridge[i];
		}
	cout<<jump(num);
	return 0;
}
