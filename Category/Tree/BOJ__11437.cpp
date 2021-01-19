#include<iostream>
#include<vector>

using namespace std;

vector<int> load[50001];
int N, K;
vector<pair<int, int>> v;
int depth[50001];
int parent[50001];
bool visited[50001];

void init() {
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		load[a].emplace_back(b);
		load[b].emplace_back(a);
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
}

void dfs(int x, int cdepth ) {
	depth[x] = cdepth; // x의 깊이는 현재 깊이인 cdepth이다. // 깊이 ++;
	for (int i = 0; i < load[x].size(); i++) {
		if (!depth[load[x][i]]) {
			parent[load[x][i]] = x; //load[x][i]의 부모는 x 이다.
			dfs(load[x][i], cdepth + 1);
		}
	}
}
int main(void) {
	init();
	dfs(1, 1);
	for (int i = 0; i < v.size(); i++) {
		int node1 = v[i].first;
		int node2 = v[i].second;
		if (depth[node1] > depth[node2]) {
			while (depth[node1] != depth[node2]) {
				node1 = parent[node1];
			}
			while (node1 != node2) {
				node1 = parent[node1];
				node2 = parent[node2];
			}
			cout << node1 << '\n';
		}
		else {
			while (depth[node1] != depth[node2]) {
				node2 = parent[node2];
			}
			while (node1 != node2) {
				node1 = parent[node1];
				node2 = parent[node2];
			}
			cout << node2 << '\n';
		}
	}
	return 0;
}
