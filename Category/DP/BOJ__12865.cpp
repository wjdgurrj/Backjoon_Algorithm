#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> v;
int dp[100001];
int main(void) {
	int N, K;
	cin >> N >> K;
	v.push_back({ 0,0 });
	for (int i = 0; i < N; i++) {
		int weight, value;
		cin >> weight >> value;
		v.push_back({ weight,value });
	}
	for (int i = 1; i <= N; i++) {
		for (int j = K; j >= 1; j--) {
			if (v[i].first <= j)
				dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
		}
	}
	cout << dp[K];
	return 0;
}
