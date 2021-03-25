#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int toy[101][101];
int mid_cnt[101];
int N, M;
bool visited[101];
vector<pair<int,int>> graph[101];
vector<int> basic;
queue<int> q;


void init() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int mid, basic, cnt;
		cin >> mid >> basic >> cnt;
		graph[basic].push_back({ mid, cnt });
		mid_cnt[mid]++; // 중간 부품의 갯수를 세어주기 위해
		visited[mid] = true; // basic 알기 위해
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			q.push(i);
			basic.push_back(i);
			toy[i][i] = 1;
		}
	}
}

void bfs() {
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < graph[current].size(); i++) {
			for (int j = 1; j <= N; j++) {
				toy[graph[current][i].first][j] += toy[current][j] * graph[current][i].second;
			}
			mid_cnt[graph[current][i].first]--;
			if (mid_cnt[graph[current][i].first] == 0) {
				q.push(graph[current][i].first);
			}
		}
	}
}

int main(void) {
	init();
	bfs();
	for (int i = 0; i < basic.size(); i++) {
		cout<< basic[i] << ' ' << toy[N][basic[i]] << '\n';
	}
	return 0;
}
