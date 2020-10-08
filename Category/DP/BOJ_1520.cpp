#include <iostream>
#include <vector>
#include<cstring>
using namespace std;

int N, M;
int arr[501][501];
int d[501][501];
int movement[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int dp(int x, int y) {
	if (x == N && y == M) {
		return 1;
	}
	if (d[x][y] != -1) {
		return d[x][y];
	}
	if (d[x][y] == -1) {
		d[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + movement[i][0];
			int ny = y + movement[i][1];
			if (nx > 0 && nx <= N && ny > 0 && ny <= M) {
				if (arr[nx][ny] < arr[x][y]) {
					d[x][y] += dp(nx, ny); // 조건에 맞는 동서남북에 있는 값이 더해져야함
				}
			}
		}
	}
	return d[x][y];
}
int main(void) {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			d[i][j] = -1;
		}
	}
	cout << dp(1, 1);
	return 0;
}
