#include<iostream>
#include<vector>

using namespace std;
vector<int> v;
int N, S, answer;

void dfs(int n, int result) {
	if (result == S && n == N) {
		answer++;
		return;
	}
	if (n == N) {
		return;
	}
	dfs(n + 1, result + v[n]);
	dfs(n + 1, result);
}
int main(void) {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.emplace_back(num);
	}
	dfs(0, 0);
	if (S == 0) {
		answer--;
	}
	cout << answer;
	return 0;
}
