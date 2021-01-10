#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int T, k, result;
int d[10001][101];
vector<pair<int,int>> coin;

void init() {
	cin >> T >> k;
	for (int i = 0; i < k; i++) {
		int p,n;
		cin >> p >> n;
		coin.push_back({ p,n });
	}
	sort(coin.begin(), coin.end(),greater<>());
}

int dp(int idx, int value) {
	if (value == T) {
		return 1;
	}
	if (idx >= k) {
		return 0;
	}
	if (d[value][idx] != -1) {
		return d[value][idx];
	}
	d[value][idx] = 0;

	int cnt = min(coin[idx].second, ((T - value) / coin[idx].first));

	for (int i = 0; i <= cnt; i++) {
		d[value][idx] += dp(idx + 1, value + (i * coin[idx].first));
	} 

	return d[value][idx];
	/* 그냥 일반적인 dfs돌리니 시간초과가 뜸,, 값을 저장해 놓는 것의 중요성,,,
	for (int i = idx; i < coin.size(); i++) {
		int cnt = min(coin[i].second,(value / coin[i].first));
		for (int j = cnt; j > 0; j--) {
			dp(i + 1, value - (j * coin[i].first));
		}
	}
	*/
}
int main(void) {
	init();
	memset(d, -1, sizeof(d));
	cout << dp(0, 0);
	
	return 0;
}
