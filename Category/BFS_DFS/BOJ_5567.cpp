#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> v[501];
bool visit[501];
int n, m, answer, cnt;
// dfs로 하려다 보니까 방문처리 하기가 까다로워서 bfs로 접근했음

void bfs() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int n = q.size();
		while (n--) {
			int current = q.front();
			q.pop();
			for (int i = 0; i < v[current].size(); i++) {
				if (!visit[v[current][i]]) {
					visit[v[current][i]] = true;
					q.push(v[current][i]);
					answer++;
				}
			}
		}
		if (++cnt > 1) {
			break;
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		v[num1].push_back(num2);
		v[num2].push_back(num1);
	}
	visit[1] = true;
	bfs();
	cout << answer;
	return 0;
}
