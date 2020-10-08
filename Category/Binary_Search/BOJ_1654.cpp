#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long> v;
int main(void) {
	long long n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		v.emplace_back(num);
	}
	sort(v.begin(), v.end());
	long long value = 0;
	long long high = v[n - 1];
	long long low = 1;
	while (low <= high) {
		value = 0;
		long long mid = (high + low) / 2;
		for (int i = 0; i < n; i++) {
			value += v[i] / mid;
		}
		if (value >= m) {
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	cout << high;
	return 0;
}
