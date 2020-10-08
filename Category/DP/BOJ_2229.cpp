#include<iostream>
#include<algorithm>

using namespace std;

int student[1001];
int dp[1001] = { 0, };
int camp(int n) {
	for (int i = 1; i <= n; i++) {
		int low = 9999999, high = 0;
		for (int j = i; j >= 1; j--) {
			low = min(low, student[j]);
			high = max(high, student[j]);
			dp[i] = max(dp[i], high - low + dp[j - 1]);
		}
	}
	return dp[n];
}

int main(void) {
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cin >> student[i];
	}
	cout<<camp(num);
}
