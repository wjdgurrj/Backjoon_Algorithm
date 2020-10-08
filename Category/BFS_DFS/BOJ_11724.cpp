#include<iostream>
#include<vector>

using namespace std;

bool visit[1001];
vector<int> node[1001];
int cnt;

void dfs(int n) {
	visit[n] = true;
	for (int i = 0; i < node[n].size(); i++) {
		int next = node[n][i];
		if (visit[next] == 0) {
			dfs(next);
		}
	}
}
int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		node[num1].emplace_back(num2);
		node[num2].emplace_back(num1);
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
