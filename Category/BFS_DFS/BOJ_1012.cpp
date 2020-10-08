#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

bool visit[51][51];
int chu[51][51];
int test, m, n, k;
vector<pair<int, int>> v;
int d[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int nx, ny;



void jirung(int y, int x) {
	
	for (int i = 0; i < 4; i++) {
		nx = x + d[i][0];
		ny = y + d[i][1];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m){
			continue;
		}
		if (chu[ny][nx] && !visit[ny][nx]) {
			visit[ny][nx] = true;
			jirung(ny, nx);
		}
	}
	
}
int main(void) {
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> m >> n >> k;
		memset(visit, false, sizeof(visit));
		memset(chu, 0, sizeof(chu));
		int counta = 0;

		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y;
			chu[y][x] = 1;
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (chu[i][j] && !visit[i][j]) {
					counta++;
					visit[i][j] = true;
					jirung(i, j);
				}
			}
		}
		cout << counta << endl;
	}
	return 0;
}
