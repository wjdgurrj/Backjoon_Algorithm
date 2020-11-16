#include<iostream>
#include<string>

using namespace std;

char result[500050];

// 1. 무조건 작은 숫자 제거 -> 틀림 
// 2. 4중 포문 돌렸더니 -> 시간초과 (답은 나옴)
// 3. 문자열 폭발과 같이 스택 사용하기 
int main(void) {
	int n, k;
	string s;
	cin >> n >> k >> s;
	int idx = 0;
	for (int i = 0; i < s.length(); i++) {
		while (k > 0 && idx != 0 && result[idx] < s[i]) {
			idx--;
			if (idx < 0) {
				idx = 0;
			}
			k--;
		}
		result[++idx] = s[i];
	}
	for (int i = 1; i <= idx - k; i++) {
		cout << result[i];
	}
	return 0;
}
// ------------------------------------------------------
// 틀린 코드 -------------------------------------------
/*
int main(void) {
	int n, k;
	string s;
	cin >> n >> k >> s;
	for (int i = 0; i < n; i++) {
		v[s[i] - 48].emplace_back(i);
	}
	for (int m = 9; m >= 0; m--) {
		if (k == 0) break;
		for (int j = 0; j < v[m].size(); j++) {
			if (k == 0) break;
			for (int h = 0; h <= m; h++) {
				if (k == 0) break;
				for (int l = 0; l < v[h].size(); l++) {
					if (k == 0 || (v[m][j] < v[h][l])) break;
					if (v[h][l] < v[m][j] && tf[v[h][l]] == false) {
						tf[v[h][l]] = true;
						k--;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (tf[i] == false) {
			cout << s[i];
		}
	}
	return 0;
}
*/
