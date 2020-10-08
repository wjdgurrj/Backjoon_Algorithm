#include<iostream>
#include<algorithm>
using namespace std;

int mn[1001][1001];

int main(void) {
	int a,n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mn[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1)continue;
			if (i == 1) mn[i][j] += mn[i][j - 1];
			else if (j == 1) mn[i][j] += mn[i-1][j];
			else mn[i][j] += max(mn[i][j-1],max(mn[i-1][j - 1], mn[i - 1][j]));
		}

	}
	cout << mn[n][m];
}
