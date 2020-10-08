#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
vector<int> maxcnt;
int main(void) {
	int n;
	cin >> n;
	v.emplace_back(0);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.emplace_back(num);
	}
	maxcnt.emplace_back(0);
	for (int i = 1; i <= n; i++) {
		if (maxcnt[i - 1] + v[i] > v[i]) {
			maxcnt.emplace_back(maxcnt[i - 1] + v[i]);
		}
		else {
			maxcnt.emplace_back(v[i]);
		}
	}
	int result = maxcnt[1];
	for (int i = 1; i <= n; i++) {
		result = max(result, maxcnt[i]);
	}
	cout << result;
	return 0;
}
