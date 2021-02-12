#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, result, t;
string pill;
bool visited[1501][1501];
queue<pair<int, int>> q;
char time[3] = { 'B', 'L', 'D' };
void init() {
	cin >> N >> pill;
	
}

void bfs() {
	q.push({ 0,0 });
	visited[0][0] = true;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			pair<int, int> current = q.front();
			q.pop();
			if (current.first + current.second < pill.size()) {
				if (pill[current.first] == time[t] && !visited[current.first + 1][current.second]) {
					q.push({ current.first + 1, current.second });
					visited[current.first + 1][current.second] = true;
				}
				if (pill[pill.size() - 1 - current.second] == time[t] && !visited[current.first][current.second + 1]) {
					q.push({ current.first, current.second + 1 });
					visited[current.first][current.second + 1] = true;
				}
			}
		}
		result++;
		t = (t + 1) % 3;
	}
}
// 모든 경우 재귀로 풀면 시간초과 난다.
/*
void dfs(int cnt, string s, char time) {
	result = max(result, cnt);
	if (s.size() == 0) {
		return;
	}
	if (time == 'B') {
		if (s[0] == 'B') {
			string s2 = s.substr(1, s.size() - 1);
			dfs(cnt + 1, s2, 'L');
		}
		if (s[s.size() - 1] == 'B') {
			string s2 = s.substr(0, s.size() - 1);
			dfs(cnt + 1, s2, 'L');
		}
	}
	if (time == 'L') {
		if (s[0] == 'L') {
			string s2 = s.substr(1, s.size() - 1);
			dfs(cnt + 1, s2, 'D');
		}
		if (s[s.size() - 1] == 'L') {
			string s2 = s.substr(0, s.size() - 1);
			dfs(cnt + 1, s2, 'D');
		}
	}
	if (time == 'D') {
		if (s[0] == 'D') {
			string s2 = s.substr(1, s.size() - 1);
			dfs(cnt + 1, s2, 'B');
		}
		if (s[s.size() - 1] == 'D') {
			string s2 = s.substr(0, s.size() - 1);
			dfs(cnt + 1, s2, 'B');
		}
	}
	return;
}
*/
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	init();
	//dfs(0, pill, 'B');
	bfs();
	cout << result - 1;
	return 0;
}
