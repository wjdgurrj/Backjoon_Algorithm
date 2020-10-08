#include<iostream>
#include<vector>

using namespace std;

vector<int> parent[100001];
bool visit[100001];
int result[100001];

void dfs(int n) {
	visit[n] = true;
	for (int i = 0; i < parent[n].size(); i++) {
		int next = parent[n][i];
		if (visit[next] == false) {
			dfs(next);
			result[next] = n;
		}
	}
}
int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int num1, num2;
		cin >> num1 >> num2;
			parent[num2].emplace_back(num1);
			parent[num1].emplace_back(num2);
	}
	dfs(1);
	for (int i = 2; i <= N; i++) {
		cout << result[i] << '\n';
	}
	return 0;
}
