#include<iostream>
#include<algorithm>
using namespace std;

int v[201];
int arr[201];

int main(void) {
	int n,result = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		v[i] = num;
}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				cnt = max(cnt, arr[j]);
			}
		}
		arr[i] = cnt + 1;
		result = max(result, arr[i]);
	}
	cout << n - result << endl;
	
	return 0;
	
}
