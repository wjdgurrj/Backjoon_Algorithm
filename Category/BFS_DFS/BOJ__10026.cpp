#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<cstring>

using namespace std;
int cnt1 , cnt2;
queue<pair<int,int>> q;
bool visit[101][101];
char color[101][101];
int movement[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
void bfs(int x,int y) {
	pair<int,int> current;
	q.push(make_pair(x,y));
	visit[x][y] = true;
	while (!q.empty()) {
		current = q.front();
		q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = current.second + movement[i][0];
				int ny = current.first + movement[i][1];
				if (visit[ny][nx] == false && color[current.first][current.second] == color[ny][nx]) {
					visit[ny][nx] = true;
					q.push(make_pair(ny, nx));
				}
		}
	}
}
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char a;
			cin >> a;
			color[j][i] = a;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[j][i] == false) {
				bfs(j,i);
				cnt1++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (color[i][j] == 'R') {
				color[i][j] = 'G';
			}
		}
	}
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[j][i] == false) {
				bfs(j, i);
				cnt2++;
			}
		}
	}
	cout << cnt1 << ' ' << cnt2 << endl;
	return 0;
}
