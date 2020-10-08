#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

bool visit[52][52];
int island[52][52];
int w, h;
queue<pair<int, int>> q;
int movement[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1} };

vector<int> result;
void bfs(int x,int y) {
	visit[x][y] = true;
	pair<int, int> current;
	q.push(make_pair(x,y));
	while (!q.empty()) {
		current = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = current.second + movement[i][0];
			int ny = current.first + movement[i][1];
			if (nx >= 1 || nx <= w || ny >= 1 || ny <= h) {
				if (island[ny][nx] == 1 && visit[ny][nx] == false) {
					q.push(make_pair(ny, nx));
					visit[ny][nx] = true;
				}
			}
		}
	}
}
int main(void) {

	while (1) {
		int cnt = 0;
		memset(visit, false, sizeof(visit));
		memset(island, 0, sizeof(island));
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				int num;
				cin >> num;
				island[i][j] = num;
			}
		}
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (visit[i][j] == false && island[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		result.emplace_back(cnt);
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	return 0;
}
