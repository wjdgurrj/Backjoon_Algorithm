#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int tc,n, ack = 0;
string v[51][10001];
vector<int> result;
int main(void) {
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		ack = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
		sort(&v[i][0],&v[i][n]);
		for (int j = 0; j < n; j++) {
			string a = v[i][j];
			for (int k = j + 1; k < n; k++) {
				if (a[0] != v[i][k][0]) {
					break;
				}
				if (a.size() > v[i][k].size()) {
					break;
				}
				string b = v[i][k].substr(0, a.size());
				if (a == b) {
					ack = 1;
					break;
				}
			}
			if (ack == 1) {
				break;
			}
		}
		if (ack == 1) {
			result.emplace_back(1);
		}
		else {
			result.emplace_back(0);
		}
	}
	for (int i = 0; i < tc; i++) {
		if (result[i] == 0) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}
