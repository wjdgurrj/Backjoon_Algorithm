#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
int n, m;
int value;
int maximum = -1;
vector<int> v[10001];
bool visit[10001];
int result[10001] = { 0, };
void dfs(int num) {
	visit[num] = true;
	for (int i = 0; i < v[num].size(); i++) {
		int next = v[num][i];
		if (visit[v[num][i]] == false) {
			value++;
			dfs(next);
		}
	}
}
int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].emplace_back(a);
	}
	
	for (int i = 1; i <= n; i++) {
		if (v[i].size() != 0) {
			memset(visit, false, sizeof(visit));
			value = 0;
			dfs(i);
			if (maximum < value) {
				maximum = value;
			}
			result[i] = value;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (result[i] == maximum) {
			cout << i << ' ';
		}
	}
	return 0;
}
