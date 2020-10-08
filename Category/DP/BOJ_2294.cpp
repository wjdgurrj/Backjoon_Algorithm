#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int N, K;
int d[10001];
vector<int> v;

void dp() {
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (i - v[j] <= 0) {
				break;
			}
			d[i] = min(d[i], d[i - v[j]] + 1);
		}
	}
}
int main(void) {
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		d[i] = 30000;
	}
	for (int i = 0; i < N ;i++) {
		int num;
		cin >> num;
		v.emplace_back(num);
		if (num <= 10000) {
			d[num] = 1;
		}
	}
	
	sort(v.begin(), v.end());
	dp();
	if (d[K] == 30000) {
		cout << -1;
		return 0;
	}
	cout << d[K];
	return 0;
}
