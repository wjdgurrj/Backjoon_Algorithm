#include<iostream>
#include<vector>

using namespace std;

vector<int> v;
// 첫자리에 올 수 있는게 2 3,5 7 뿐
// 그 이후로 들어오는 수 소수인지 판별
int N;
int digit[4] = { 2,3,5,7 };

bool isprime(int n) { // 소수 판별하기
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
void dfs(int n, int cnt) {
	if (cnt == N ) {
		v.emplace_back(n);
		return;
	}
	for (int i = 1; i < 10; i++) {
		int next = n * 10 + i;
		if (isprime(next) == true) {
			dfs(next, cnt + 1);
		}
	}
}
int main(void) {
	cin >> N;
	for (int i = 0; i < 4; i++) {
		dfs(digit[i], 1);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}
