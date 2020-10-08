#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

vector<pair<int,int>> v[100001];
int V;
int idx, length;
bool visit[100001];
// 1. root 찾아서 놓기, 2. 한 군데서 젤 먼 노드 탐색, 거기서 젤 먼 노드 다시 탐색 거리 측정,
// 

void dfs(int n, int len) {
	if (visit[n] != 0) {
		return;
	}
	if (length < len) {
		length = len;
		idx = n;
	}
	visit[n] = true;

	for (int i = 0; i < v[n].size(); i++) {
		pair<int,int> current = v[n][i];
		if (visit[current.first] == false) {
			dfs(current.first, len + current.second);
			visit[current.first] = false;
		}
	}
}

int main(void) {
	cin >> V;
	for (int i = 1; i <= V; i++) {
		int num;
		cin >> num;
		while (1) {
			int value, len;
			cin >> value;
			if (value == -1) {
				break;
			}
			cin >> len;
			v[num].push_back({ value,len });
		}
	}
	dfs(1, 0);
	memset(visit, false, sizeof(visit));
	dfs(idx, 0);

	cout<< length;
	
	return 0;
}
