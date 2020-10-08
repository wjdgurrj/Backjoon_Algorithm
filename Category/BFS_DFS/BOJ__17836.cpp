#include<iostream>
#include<queue>

using namespace std;
int arr[103][103];
bool visit[103][103][2];
int n, m, t;
queue<pair<pair<int, int>, pair<int,int>>> q;
int movement[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
void bfs() {
	q.push({ {0,0},{0,0} });
	visit[0][0][0] = true;
	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int time = q.front().second.first;
		int d = q.front().second.second;
		q.pop();
		
		if (time > t) continue;
		if (cx == n - 1 && cy == m - 1) {
			cout << time;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + movement[i][0];
			int ny = cy + movement[i][1];
			
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && visit[nx][ny][d] == false) {
				if (arr[nx][ny] == 2) {
					q.push({ {nx,ny},{time + 1,d + 1} });
					visit[nx][ny][d] = true;
				}
				if (arr[nx][ny] == 1 && d == 1) {
					q.push({ {nx,ny},{time + 1,d} });
					visit[nx][ny][d] = true;
				}
				if (arr[nx][ny] == 0) {
					q.push({ {nx,ny},{time + 1,d} });
					visit[nx][ny][d] = true;
				}
			}
		}
	}
	cout << "Fail";
	return;
}
int main(void) {
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			arr[i][j] = num;
		}
	}
	bfs();

	return 0;
}
