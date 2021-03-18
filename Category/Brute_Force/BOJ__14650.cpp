#include<iostream>

using namespace std;
int d[9];
void dp(int n) {
	d[0] = 0;
	d[1] = 2;
	d[2] = 6;
	if (n > 3) {
		for (int i = 3; i < n; i++) {
			d[i] = 3 * d[i - 2] + 2 * d[i - 1];
		}
	}
}
int main(void) {
	int N;
	cin >> N;
	dp(N);
	cout << d[N-1] << endl;
	
	return 0;
	
}
