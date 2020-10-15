#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> v;
int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back({ end,start });
	}
	sort(v.begin(), v.end());
	int end = v[0].first;
	if (N == 1) {
		cout << 1;
		return 0;
	}
	int index = 1;
	int result = 1;
	for (int i = index; i < N; i++) {
		if (end <= v[i].second) {
			end = v[i].first;
			result++;
		}
	}
	cout << result;
	return 0;
}
