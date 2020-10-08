#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, num;
int moveto[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
queue<pair<int, int>> q;
vector<int> result;
int d[101][101] = { 0 , }; // 방문처리
void visit(int sx, int sy, int lx, int ly) {// 방문처리
	for (int i = sx; i < lx; i++) {
		for (int j = sy; j < ly; j++) {
			d[j][i] = 1;
		}
	}
}
void bfs(int x, int y ) {
	int sum = 0;
	pair<int, int> current;
	q.push(make_pair(x, y));
	d[x][y] = 1; // 처음지점 방문 해줘야 하니 방문처리
	while (!q.empty()) {
		current = q.front();
		q.pop();
		sum++;
		for (int i = 0; i < 4; i++) {
			int nx = current.first + moveto[i][0];
			int ny = current.second + moveto[i][1];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n && d[nx][ny] == 0) {
				d[nx][ny] = 1; // 방문처리
				q.push(make_pair(nx, ny)); //값 대입
			}
		}
	}
	result.emplace_back(sum); //넓이 측정
}
int main(void) {
	cin >> m >> n >> num;
	for (int i = 0; i < num; i++) {
		int sx, sy, lx, ly;
		cin >> sx >> sy >> lx >> ly;
		visit(sx, sy, lx, ly);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (d[i][j] == 0) { //방문되어있지 않으면
				bfs(i, j);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << endl; // 넓이의 갯수
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	return 0;
}
