#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main() {
	long long int N, answer;
	cin >> N;
	vector<pair<long long int, long long int> > cage;
	cage.push_back(make_pair(1, 2));

	if (N == 1) {
		cout << 3;
	}
	else {
		for (int i = 1; i < N; i++) {
			cage.push_back(make_pair((cage[i - 1].first + cage[i - 1].second)%9901, (cage[i - 1].first * 2 + cage[i - 1].second)%9901));
		}
			answer = (cage[N - 1].first + cage[N - 1].second) % 9901;
			cout << answer;
	}
	
	return 0;
}
