#include<iostream>

using namespace std;
long long d[91];
int N;
long long dp(int n) {
	d[1] = 1;
	d[2] = 1;
	d[3] = 2;
	for (int i = 4; i <= n; i++) {
		d[i] = d[i - 2] + d[i - 1];
	}
	return d[n];
}
int main(void) {
	cin >> N;
	cout << dp(N);
	return 0;
}
