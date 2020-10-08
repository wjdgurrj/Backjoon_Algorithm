#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int d[1001];
vector<int> v;
int N;
void dp() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], d[i - j] + v[j-1]);
		}
	}
}
int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		v.emplace_back(num);
		d[i] = num;
	}
	dp();
	cout << d[N];
	return 0;
}
