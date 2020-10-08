#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v1;
vector<int> v2;

int grape(int n) {
	v2.emplace_back(0);
	v2.emplace_back(v1[1]);
	v2.emplace_back(v1[1] + v1[2]);
	if (n == 0) return 0;
	if (n == 1) return v2[1];
	if (n == 2)return v2[2];
	
	for (int i = 3; i <= n;i++) {
		v2.emplace_back(max(v2[i - 1], max(v2[i - 2] + v1[i], v2[i - 3] + v1[i - 1] + v1[i])));
	}
	return v2[n];
}

int main(void) {
	int n;
	cin >> n;
	v1.emplace_back(0);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v1.emplace_back(x);
	}
	cout << grape(n);
	return 0;
}
