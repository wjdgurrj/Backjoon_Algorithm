#include<iostream>
#include<algorithm>
using namespace std;
long long int d[301];
long long int result[301];
long long int dp(int n) {
	if (n == 1) {
		return result[1] = d[1];
	}
	if (n == 2) {
		return result[2] = d[1] + d[2];
	}
	if (n == 3) {
		return max(d[2]+d[3],d[1] + d[3]);
	}
	if (result[n] != 0) return result[n];
	for (int i = 4; i <= n; i++) {
		result[i] = max(dp(i - 2) + d[i], dp(i - 3) + d[i] + d[i - 1]);
	}
	return result[n];
	
}
int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		d[i] = num;
	}
	cout << dp(n) << '\n';
	return 0;
}
