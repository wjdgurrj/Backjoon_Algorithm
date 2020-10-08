#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

int n, m;
int movement[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int arr[101][101] = { 0, };
queue<pair<int, int>> q;
//방문한 값을 저장 해주어야 함!
 void miro() {
	int nx, ny;
	pair<int, int> current;//현재 위치
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = current.second + movement[i][0];
			ny = current.first + movement[i][1];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && arr[ny][nx] == 1) {
				q.push(make_pair(ny, nx));
				arr[ny][nx] = arr[current.first][current.second] + 1;
			}
		}
	}
	return;
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		for(int j = 0; j < m; j++) {
			if (x[j] == '1') {
				arr[i][j] = 1;
			}
		}
	}
	miro();
	cout << arr[n-1][m-1] << endl;
	return 0;
}
