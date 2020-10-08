#include <iostream>

using namespace std;

int d[16][16];
int arr[16][16];
int movement[2][2] = { {0,1},{1,0} };
int N, M, K, num = 1;

pair<int, int> k;
void dp(int x,int y) // 처음시작
{
	for (int i = 2; i <= x; i++) {
		for (int j = 2; j <= y; j++) {
			d[i][j] = d[i - 1][j] + d[i][j - 1];
		}
	}
}
void dpk(int x, int y) // k가 0이 아닐때 
{
	for (int i = x + 1; i <= N; i++) {
		for (int j = y + 1; j <= M; j++) {
			d[i][j] = d[i - 1][j] + d[i][j - 1];
		}
	}
}
int main(void)
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			arr[i][j] = num;
			if (num == K) { // K 지점 인덱스 저장
				k.first = i;
				k.second = j;
			}
			num++;
			if (i == 1 || j == 1)
			{
				d[i][j] = 1; //가로세로 첫줄은 전부 1
			}
		}
	}
	if (K != 0) { // K를 지나야 하면
		dp(k.first, k.second); // K까지 이동
		for (int i = k.first; i <= N; i++) {  // K 번째 열행 전부 d[k.first][k.second]
			for (int j = k.second; j <= M; j++) {
				if (i == k.first || j == k.second) {
					d[i][j] = d[k.first][k.second];
				}
			}
		}
		dpk(k.first, k.second); //  끝까지 이동
	}
	else { // K == 0 이면 그냥 처음부터 끝까지 이동
		dp(N, M);
	}
	cout << d[N][M];
	return 0;
}
