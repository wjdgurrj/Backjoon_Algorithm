#include<iostream>
#include<vector>

using namespace std;

vector<vector<long long int>> arr(101, vector<long long int>(10, 0));
//2차원벡터 arr[101][10] 을 전부 0으로 초기화

long long int stair(int n) {
	long long int sum = 0;
	for (int i = 0; i < 10; i++) {
		arr[0][i] = 1;
	}
	for (int i = 1; i < 101; i++) {
		for (int j = 0; j < 10; j++) {
			if (j - 1 >= 0) {
				arr[i][j] += (arr[i - 1][j - 1]) % 1000000000;
			}
			if (j + 1 <= 9) {
				arr[i][j] += (arr[i - 1][j + 1]) % 1000000000;
			}
		}
	}
	for (int i = 1; i < 10; i++) {
		sum += (arr[n-1][i])%1000000000;
	}
	return sum%1000000000;
}

int main(void) {
	int n;
	cin >> n;
	cout << stair(n) << endl;
	return 0;
}
