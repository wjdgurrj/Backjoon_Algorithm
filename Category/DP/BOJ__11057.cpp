#include<iostream>

using namespace std;
int d[1001][10];
int N;
int main(void) {
	cin >> N;
	for (int i = 0; i < 10; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				d[i][k] += d[i - 1][j];
				d[i][k] = (d[i][k]) % 10007;
			}
		}
	}
	int value = 0;
	for (int i = 0; i < 10; i++) {
		value += d[N][i];
	}
	value = value % 10007;
	cout << value;
	return 0;
}
