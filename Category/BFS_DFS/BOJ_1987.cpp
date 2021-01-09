#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

bool visited[26];
char arr[21][21];
int R, C, result = 0;
int movement[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void init() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
}

void dfs(int x, int y, int num) {
	visited[arr[x][y] - 65] = true;
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + movement[i][0];
		int ny = y + movement[i][1];
		if (nx >= 0 && ny >= 0 && nx < R && ny < C && visited[arr[nx][ny] - 65] == false) {
			visited[arr[nx][ny] - 65] = true;
			dfs(nx, ny, num + 1);
			visited[arr[nx][ny] - 65] = false;
		}
	}
	if (cnt == 0) {
		result = max(num, result);
		return;
	}
}

int main(void) {
	init();
	dfs(0, 0, 1);
	cout << result;
	return 0;
}
