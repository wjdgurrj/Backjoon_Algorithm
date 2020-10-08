#include<iostream>

using namespace std;

int d[1001];
int c[1001];

int tyle(int n) {
	d[0] = 1; d[1] = 1;  d[2] = 5;
	if (n == 0)return 1;
	if (n == 1)return 1;
	if (n == 2)return 5;
	if (d[n] != 0)return d[n];
	for(int j= 3;j<=n;j++){
	d[j] = d[j-1] + d[j-2] * 4;
	for (int i = j - 3; i >= 0; i--) {
		if ((j-i) % 2 )
			d[j] += 2 * d[i];
		else
			d[j] += 3 * d[i];
		}
	}
	int result = d[n];
	return result;
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		cout << tyle(c[i]) << '\n';
	}
}
