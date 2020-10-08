#include<iostream>
#include<queue>
#include<vector>
#include<stdlib.h>
#include<cstring>

using namespace std;

int n, k;
int nx, ny;
int board[300][300];
bool visit[300][300];
int arr[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };
queue<pair<int, int>> q;
pair<int, int> start;
pair<int, int> department;
void reset() {
	for (int i = 0; i < 300; i++) {
		for(int j = 0; j < 300; j++){
			board[i][j] = 0;
		}
	}
}
int chess(int k) {
	reset();
	pair<int,int> current;
	q.push(make_pair(start.second, start.first));
	while (!q.empty()) {
		current.first = q.front().first;
		current.second = q.front().second;
		q.pop();
		if (start.first == department.first && start.second == department.second) {
			return board[current.first][current.second];
			break;
		}
		
		for (int i = 0; i < 8; i++) {
			nx = current.second + arr[i][0];
			ny = current.first + arr[i][1];
			if (nx >= 0 && nx < k && ny >= 0 && ny < k && !visit[ny][nx]) {
				q.push(make_pair(ny, nx));
				board[ny][nx] = board[current.first][current.second] + 1;
				visit[ny][nx] = true;
			}
		}
	}
	return board[department.second][department.first];
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		memset(visit,false,sizeof(visit));
		cin >> k;
		cin >> start.first >> start.second >> department.first >> department.second;
		cout << chess(k) << '\n';
	}
	return 0;
}
