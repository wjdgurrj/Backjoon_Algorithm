#include<iostream>
#include<string>
#include <stdlib.h>
using namespace std;

int main(void) {
	string B;
	int A, result = 1;
	cin >> A >> B;
	int b = atoi(B.c_str());
	while (b != 0) {
		if (b % 2 == 1 && b % 10 != 1) {
			cout << -1 << endl;
			return 0;
		}

		else if (b % 10 == 1) {
			B = B.substr(0, B.length() - 1);
			b = atoi(B.c_str());
			result++;
		}
		
		else {
			b = b / 2;
			B = to_string(b);
			result++;
		}
		if (A == b) {
			cout << result << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
