#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int d[101][101][101];

int main(void) {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			for (int k = 1; k <= s3.length(); k++) {
				if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
					d[i][j][k] = d[i - 1][j - 1][k - 1] + 1;
				}
				else {
					int a = max(max(d[i - 1][j][k], d[i][j - 1][k]), d[i][j][k - 1]);
					int b = max(max(d[i - 1][j - 1][k], d[i][j - 1][k - 1]), d[i - 1][j][k - 1]);
					d[i][j][k] = max(a, b);
				}
			}
		}
	}
	cout << d[s1.length()][s2.length()][s3.length()];
	return 0;
}
