#include<iostream>

using namespace std;

int arr[1001];
int main(void) {
	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr[num] = 1;
	}
	int k = 0;
	int cnt = 0;
	for (int i = 0; i < 1001; i = i+k) {
		if (arr[i] == 1) {
			k = L;
			cnt++;
		}
		else {
			k = 1;
		}
	}
	cout << cnt;
	return 0;
}
