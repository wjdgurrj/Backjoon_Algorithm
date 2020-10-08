#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int result[5001][5001];
int main(void) {
	string s;
	int n;
	cin >> n >> s;
	string re;
	re = s;
	reverse(s.begin(), s.end());
	for (int i = 1; i <= re.size(); i++) {
		for (int j = 1; j <= s.size(); j++) {
			if (re[i - 1] == s[j - 1]) {
				result[i][j] = 1 + result[i - 1][j - 1];
			}
			else {
				result[i][j] = max(result[i - 1][j], result[i][j - 1]);
			}
		}
	}
	cout << n - result[n][n] << endl;
	return 0;
}
