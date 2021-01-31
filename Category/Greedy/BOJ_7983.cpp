#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> v;
int n, arr[1000001], maximum;
void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, t;
		cin >> d >> t;
		v.push_back({ t,d });
	}
	sort(v.begin(), v.end(), greater<>());
	for (int i = 0; i < n; i++) {
		arr[i] = v[i].first;
	}
}
/*
void solution() {
	int idx = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = v[i].first; j > v[i].first - v[i].second; j--) {
			if (j <= 0) {
				break;
			}
			if (result[j] == 1) {
				idx++;
				if (j - idx <= 0) {
					break;
				}
				result[j - idx] = 1;
			}
			if (result[i] == 0) {
				result[j] = 1;
				idx = 0;
			}

		}
	}
}
*/

void solution() {
	int idx = 0;
	for (int i = 0; i < n ; i++) {
		if (arr[i] - v[i].second > arr[i + 1]) {
			int result = v[i].first - v[i].second - arr[i + 1];
			maximum = max(maximum, result);
		}
		else {
			maximum = 0;
			arr[i + 1] = arr[i] - v[i].second;
		}
	}
}

int main(void) {
	init();;
	solution();
	cout << maximum;
	return 0;
}
