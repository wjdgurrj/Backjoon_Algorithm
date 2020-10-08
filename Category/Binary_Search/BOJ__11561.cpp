#include<iostream>

using namespace std;

int main(void) {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		unsigned long long num;
		cin >> num;
		unsigned long long high = num;
		unsigned long long low = 0;
		while (low <= high) {
			unsigned long long mid = (low + high) / 2;
			if (mid*(mid + 1) / 2 <= num){
				low = mid + 1;
				}
			else {
				high = mid - 1;
			}
		}
		cout << low -1 <<'\n';
	}
	return 0;
}
