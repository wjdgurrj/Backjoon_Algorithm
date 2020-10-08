#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (n == 1) {
		cout << n << '\n';
	}
	else if (n == 2 ) {
		if (m < 9) {
			cout << (m + 1) / 2 << '\n';
		}
		else
			cout << 4 << '\n';
	}
	else {
		if (m <= 4) {
			cout << m << '\n';
		}
		else if (m <= 6) {
			cout << 4 << '\n';
		}
		else {
			cout << m - 2 << '\n';
		}
	}
	return 0;
	//
}
