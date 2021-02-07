#include<iostream>
#include<queue>

using namespace std;

int horse[8][2] = { {1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1} }; // 말처럼 이동
int movement[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }; // 원숭이 이동
int k, w, h;
int arr[201][201];
bool visit[201][201][31];
queue<pair<pair<int, int>, pair<int, int>>> q; //(좌표, 말처럼 이동하면 + 1  , 말 + 원숭이 이동횟수)


int bfs() {
	pair<pair<int, int>, pair<int, int>> current;
	q.push({ {0,0},{0,0} });
	while (!q.empty()) {
		current = q.front();
		q.pop();
		if (current.first.first == h - 1 && current.first.second == w - 1) {
			return current.second.second;
		}
		if (current.second.first < k) { // 말처럼 이동횟수가 K보다 작아야함
			for (int j = 0; j < 8; j++) {
				int nx = current.first.first + horse[j][0];
				int ny = current.first.second + horse[j][1];
				if (nx >= 0 && nx < h && ny >= 0 && ny < w && visit[nx][ny][current.second.first + 1] == false && arr[nx][ny] == 0) {
					visit[nx][ny][current.second.first + 1] = true;
					q.push({ {nx,ny},{current.second.first + 1,current.second.second + 1} });
				}
			}
		}
		for (int i = 0; i < 4; i++) { // 원숭이이동은 제한 없음
			int nx = current.first.first + movement[i][0];
			int ny = current.first.second + movement[i][1];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w && visit[nx][ny][current.second.first] == false && arr[nx][ny] == 0) {
				visit[nx][ny][current.second.first] = true;
				q.push({ {nx,ny},{current.second.first,current.second.second + 1} });
			}
		}

	}
	return -1;
}

int main(void) {
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int num;
			cin >> num;
			arr[i][j] = num;
		}
	}
	cout << bfs() << endl;
	return 0;
	
}
