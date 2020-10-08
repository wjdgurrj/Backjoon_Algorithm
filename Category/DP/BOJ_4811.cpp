#include<iostream>
#include<vector>

using namespace std;
long long d[31][31];
// 점화식 찾아 보려다가 개 오래 걸림,,,,,
// 잘 찾아지지도 않아서 걍 케이스 나눠서 계산해봤음
// 그랬더니 생각보다 너무 간단...... ^^ㅣ벌,,,
long long dp(int w,int h) {
	if (d[w][h] != 0) { // dp
		return d[w][h];
	}
	if (w == 0) { // 알약갯수 0개
		return 1;
	}
	if (h == 0) {
		d[w][h] += dp(w - 1, h + 1);
	}
	else {
		d[w][h] += dp(w - 1, h + 1);
		d[w][h] += dp(w, h - 1);
	}
	return d[w][h];
}
int main(void) {
	while(1){
		int num;
		cin >> num;
		if (num == 0) {
			break;
		}
		cout << dp(num, 0) << '\n';
	}
	return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
}
