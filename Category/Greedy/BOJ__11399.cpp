#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int main(void) {
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.emplace_back(num);
		sum += num;
	}
	sort(v.begin(), v.end());
	int result = sum;
	for (int i = v.size() - 1; i >= 0; i--) {
		sum -= v[i];
		result += sum;
	}
	cout << result;
	return 0;

}
