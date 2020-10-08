#include<iostream>
#include<vector>

using namespace std;

int screen[2001];

void emoticon(int n, int clip, int result) {
	if (screen[n] > result || screen[n] == 0) {
		screen[n] = result;
	}
	if (n > 1 && (screen[n - 1] == 0 || screen[n - 1] > result + 1)) {
		emoticon(n - 1, clip, result + 1);
	}
	if (clip > 0 && n + clip < 2001) {
		emoticon(n + clip, clip, result + 1);
	}
	if (n + n < 2001 && n >0) { // 저장후 붙여 넣기 2초걸림
		emoticon(n + n, n, result + 2);
	}
}
int main(void) {
	int n;
	cin >> n;
	screen[1] = 1;
	emoticon(2, 1, 2);
	cout << screen[n];
	return 0;
}
