#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
vector<int> v[1001];
bool visit[1001];
int n, m, start;
vector<int> bb;
vector<int> dd;
queue<int> q;
void bfs(int start) {
	q.push(start);
	int current;
	visit[start] = true;
	while (!q.empty()) {
		current = q.front();
		q.pop();
		bb.emplace_back(current);
			for (int i = 0; i< v[current].size(); i++) {
				if (!visit[v[current][i]]) {
					q.push(v[current][i]);
					visit[v[current][i]] = true;
				}
		}
	}
}

void dfs(int start) {
	visit[start] = true;
	dd.emplace_back(start);
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (!visit[next]) {
			dfs(next);
		}
	}
}

int main(void) {
	cin >> n >> m >> start;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	for (int i = 0; i < 1001; i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(start);
	memset(visit, false, sizeof(visit));
	bfs(start);
	for (int i = 0; i < dd.size(); i++) {
		cout << dd[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < bb.size(); i++) {
		cout << bb[i] << ' ';
	}
	return 0;
}
