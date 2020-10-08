#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
vector<int> mini;
int main(void) {
	int n,k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.emplace_back(num);
	}
	sort(v.begin(), v.end());
	int result = 0;
	if (n <= k) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i < v.size(); i++) {
		mini.emplace_back(v[i] - v[i - 1]);
	}
	sort(mini.begin(), mini.end());
	for (int i = 0; i < n - k; i++) {
		result += mini[i];
	}
	cout << result;
	return 0;
}
