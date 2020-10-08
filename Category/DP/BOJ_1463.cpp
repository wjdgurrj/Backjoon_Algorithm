#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;

int jobbab(int n) {
	v.emplace_back(0);
	v.emplace_back(0);
	v.emplace_back(1);
	v.emplace_back(1);
	for (int i = 4; i <= n; i++) {
		if (i % 2 != 0 && i % 3 != 0) {
			v.emplace_back(v[i - 1] + 1);
		}
		else if (i % 2 == 0 && i % 3 != 0) {
			v.emplace_back(min(v[i - 1] + 1, v[i / 2] + 1));
		}
		else if (i % 2 != 0 && i % 3 == 0) {
			v.emplace_back(min(v[i - 1] + 1, v[i / 3] + 1));
		}
		else if (i % 2 == 0 && i % 3 == 0) {
			v.emplace_back(min(v[i/2] + 1, v[i / 3] + 1));
		}
	}
	return v[n];
}

int main(void) {
	int n;
	cin >> n;
	cout << jobbab(n) << endl;
	return 0;
}
