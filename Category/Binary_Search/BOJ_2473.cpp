#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long> v;
int N;
long long result1, result2, result3;
vector<long long> result;
void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long liquid;
		cin >> liquid;
		v.emplace_back(liquid);
	}
	sort(v.begin(), v.end());
}

void solve(int x, int y) {
	int start = y + 1;
	int last = N - 1;
	while (start <= last) {
		int mid = (start + last) / 2;
		long long value = v[mid] + v[x] + v[y];
		if (value == 0) {
			result1 = v[mid];
			result2 = v[x];
			result3 = v[y];
			break;
		}
		else if (value > 0) {
			last = mid - 1;
		}
		else {
			start = mid + 1;
		}
		if (abs(value) < abs(result1 + result2 + result3)) {
			result1 = v[mid];
			result2 = v[x];
			result3 = v[y];
		}
	}
}

int main(void) {
	init();
	result1 = v[0];
	result2 = v[(N - 1) / 2];
	result3 = v[1];
	if (N == 3) {
		cout << v[0] << ' ' << v[1] << ' ' << v[2];
		return 0;
	}
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			solve(i, j);
			if (result1 + result2 + result3 == 0) {
				break;
			}
		}
		if (result1 + result2 + result3 == 0) {
			break;
		}
	}
	result.push_back(result1);
	result.push_back(result2);
	result.push_back(result3);
	sort(result.begin(), result.end());
	cout << result[0] << ' ' << result[1] << ' ' << result[2];
	return 0;
}
