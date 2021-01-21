#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N;
int arr[16];
int result;

int chk(int x) {
	for (int i = 0; i < x; i++) {
		if (arr[i] == arr[x]) {
			return 0;
		}
		if (abs(arr[i] - arr[x]) == (x - i)) {
			return 0;
		}
	}
	return 1;
}

void dfs(int x) {
	if (x == N) {
		result++;
	}
	else {
		for (int i = 0; i < N; i++) {
			arr[x] = i;
			if (chk(x) == 1) {
				dfs(x + 1);
			}
		}
	}
}
int main(void) {
	cin >> N;
	dfs(0);
	cout << result;
	return 0;
}
