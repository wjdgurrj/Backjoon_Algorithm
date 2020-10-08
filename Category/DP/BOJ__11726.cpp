#include<iostream>

using namespace std;
long long d[1000001];
int N;
long long dp(int n) {
	d[1] = 1;
	d[2] = 2;
	d[3] = 3;
	for (int i = 4; i <= N; i++) {
		d[i] =( d[i - 1] + d[i - 2]) % 10007;
	}
	return d[n];
}
int main(void) {
	cin >> N;
	cout << dp(N);
	return 0;
}
