#include<iostream>

using namespace std;
long long int d[65];
long long int digit[65][10];
void dp(int n) {
	for (int i = 0; i < 10; i++) {
		digit[0][i] = 1;
		digit[1][i] = 10 - i;
		d[1] += digit[1][i];
	}
	d[0] = 10;
	for (int i = 2; i <= n; i++) {
		digit[i][0] = d[i - 1] ;
		d[i] += digit[i][0];
		for (int j = 1; j <10 ; j++) {
			digit[i][j] = digit[i][j - 1] - digit[i - 1][j - 1];
			d[i] += digit[i][j];
		}
	}
}

int main(void) {
	int tc;
	cin >> tc;
	dp(64);
	for (int i = 0; i < tc; i++) {
		int num;
		cin >> num;
		cout << d[num - 1] << '\n';
	}
	return 0;
}
