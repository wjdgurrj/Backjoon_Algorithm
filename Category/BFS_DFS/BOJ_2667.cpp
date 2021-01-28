#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

int arr[26][26];
bool visited[26][26];
string s[26];
int movement[4][2] = { {0,1},{1,0}, {0,-1},{-1,0} };
vector<int> v;
int N, result;
void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = s[i- 1][j - 1] - 48;
		}
	}
}
void bfs(int x, int y) {
	visited[x][y] = true;
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = current.first + movement[i][0];
			int ny = current.second + movement[i][1];
			if (nx > 0 && nx <= N && ny > 0 && ny <= N && !visited[nx][ny] && arr[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
				cnt++;
			}
		}
	}
	v.push_back(cnt);
}
int main(void) {
	init();
	for (int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if (visited[i][j] == false && arr[i][j] == 1) {
				bfs(i, j);
				result++;
			}
		}
	}
	cout << result << '\n';
	sort(v.begin(), v.end());
	for (int i = 0;i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}
