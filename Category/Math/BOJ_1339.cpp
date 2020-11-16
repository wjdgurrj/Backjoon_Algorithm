#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
int arr[26];
string s[10];
bool visited[26];
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		int num = 1;
		int size = s[i].size() - 1;
		for (int j = size; j >= 0; j--) {
			arr[s[i][j] - 65] += num;
			num *= 10;
		}
	}
	sort(&arr[0],&arr[26], greater<>());
	int sum = 0;
	int parameter = 9;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == 0) {
			continue;
		}
		sum += parameter * arr[i];
		parameter--;
	}
	cout << sum;
	return 0;
}
