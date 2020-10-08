#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int>> v(501, vector<int>(501, 0));
vector<vector<int>> sum(501, vector<int>(501, 0));

int triangle(int n) {
	sum[1][1] = v[1][1];
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				sum[i][j] = sum[i - 1][j] + v[i][j];
			}
			else if (j == i) {
				sum[i][j] = sum[i - 1][j - 1] + v[i][j];
			}
			else {
				sum[i][j] = max(sum[i - 1][j], sum[i - 1][j - 1]) + v[i][j];
			}
		}
	int maximum = 0;
	for (int i = 1; i <= n; i++) {
		maximum = max(maximum, sum[n][i]);
	}
	return maximum;
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> v[i][j];
		}
	}
	cout << triangle(n) << endl;
}
