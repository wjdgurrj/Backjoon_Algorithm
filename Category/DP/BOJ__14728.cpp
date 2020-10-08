#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int, int>> v;
int dp[10001];
int N, T;

int main(void) {
	
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		v.push_back({ num1, num2 } );
	}
	for (int i = 0; i < N; i++) {
		for (int j = T; j >= 1; j--) {
			if (j - v[i].first >=0) {
				dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
			}
		}
	}
	cout << dp[T] << endl;
	return 0;
}
