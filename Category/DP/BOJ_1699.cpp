#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int N;

int d[100001];

int dp(int n) {
	for (int j = 2; j <= n; j++) {
		int current = sqrt(j);
		for (int i = 1; i <= current; i++) {
			d[j] = min(d[j - (i * i) % 100000] + 1, d[j]);
		}
	}
	return d[n];
}
int main(void) {
	cin >> N;
	long long i = 1;
	for (int i = 1; i <= N; i++) {
		d[i] = i;
	}
	while (1) {
		d[(i*i)%100000] = 1;
		if (i*i >= N) {
			break;
		}
		i++;
	}
	
	cout << dp(N);
	return 0;
}
