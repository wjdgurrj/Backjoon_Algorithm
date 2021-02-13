#include<iostream>
#include<vector>
#include<queue>
#include <ios>
using namespace std;

int movement[4][2] = { {1,0},{-1,0} ,{0,-1}, {0,1} };//동서남북순으로 놔두기,, x,y 위치 고려해서 북남서동
int n, L, R, U, D;
bool visit[33][33];
double result;
vector<double> v;

/*
bfs로 접근하려다가 그림그려보고 dfs로 전환 , 리프노드부터 탐색해서 올라가는게 적절할 것 같음.
밞은곳 다시 안밟으면 됨...
음,,, length가 n일때 return을 하면 안되려나...
*/
void dfs(int x, int y,int length, double value) {
	if (length == 0) { // length번 움직이면 return;
		result += value;
		return;
		
	}
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + movement[i][0];
		int ny = y + movement[i][1];
		if (visit[nx][ny] == false) { //밟지 않았으면 가기 
			dfs(nx, ny, --length, value * v[i]); //1번 움직이는 것이니 --length , 
			length++; // 움직이기
			visit[nx][ny] = false;
		}
	}
}

int main(void) {
	cin >> n >> L >> R >> D >> U;
	v.emplace_back(L * 0.01);
	v.emplace_back(R * 0.01);
	v.emplace_back(D * 0.01);
	v.emplace_back(U * 0.01);
	dfs(15, 15, n, 1.0);
	cout << fixed;
	cout.precision(10);
	cout << result;
	return 0;
}
