#include<iostream>
#include<string>
#include<queue>

using namespace std;

queue<pair<int, int>> q; // queue에 넣어주면서 방문 확인
pair<int, int> current;// 현재위치
int movement[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }; //한칸식 이동
int n,m;//토마토 배열 크기
int total;//걸리는 일 수 
int arr[1001][1001] = { 0, }; //토마토 배열
int d[1001][1001];//값 저장
int nx, ny; // x,y 좌표
void map() {
	while (!q.empty()) {
		current = q.front();// 현재위치에 큐의 맨 앞 값을 저장
		q.pop();// 방문 해줬으니 빼준다.
		for (int i = 0; i < 4; i++) {
			nx = current.second + movement[i][0]; // x축 양 옆 이동
			ny = current.first + movement[i][1];// y축 양 옆 이동
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) { // nx, ny가 m,n 범위에 있으면
				if (arr[ny][nx] == 0 && d[ny][nx] == -1) { // 익지 않은 토마토가 있고, 방문하지 않았다면
					d[ny][nx] = d[current.first][current.second] + 1; // 현재일수 + 1 해주기
					q.push(make_pair(ny, nx)); // 다음번에 방문하기 위해 값 큐에 저장
				}
			}
		}
	}
	total = 0;
	for (int i = 0; i < n; i++) {//d[i][j]에 저장되어있는 값중 최댓값 출력 = 전부 익는데 최소로 걸리는 날짜
		for (int j = 0; j < m; j++) {
			total = max(total, d[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {// 탐색이 끝나고 arr값중 0이 있고, 방문하지 않은 값이 있다면 -1 처리
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && d[i][j] == -1) {
				total = -1;
			}
		}
	}
	return;
}

int main(void) {
	cin >> m>>n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			arr[i][j] = x;
			d[i][j] = -1;
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
				d[i][j] = 0;
			}
		}
	}
	map();
	cout << total << endl;
	return 0;
}
