#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

vector<int> tree[100001];
vector<int> parent[100001];
vector<pair<int,int>> node;
int N, M;
bool visited[100001];

void init() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;
		tree[x].emplace_back(y);
		tree[y].emplace_back(x);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		node.push_back({ x,y });
	}
}

void dfs(int x) {
	for (int i = 0; i < tree[x].size(); i++) {
		if (!visited[tree[x][i]]) {
			for (int j = 0; j < parent[x].size(); j++) {
				parent[tree[x][i]].emplace_back(parent[x][j]);
			}
			parent[tree[x][i]].emplace_back(tree[x][i]);
			visited[tree[x][i]] = true;
			dfs(tree[x][i]);
			visited[tree[x][i]] = false;
		}
	}
}

int main(void) {
	init();
	visited[1] = true;
	parent[1].emplace_back(1);
	dfs(1);
	for (int i = 0; i < M; i++) {
		int size = parent[node[i].first].size();
		if (parent[node[i].first].size() > parent[node[i].second].size()) {
			size = parent[node[i].second].size();
		}
		int result;
		for (int j = size - 1; j >= 0; j--) {
			result = 0;
			for (int k = size - 1; k >= 0; k--) {
				if (parent[node[i].first][j] == parent[node[i].second][k]) {
					result = parent[node[i].first][j];
				}
			}
			if (result != 0) {
				break;
			}
		}
		cout << result << '\n';
	}
	return 0;
}
