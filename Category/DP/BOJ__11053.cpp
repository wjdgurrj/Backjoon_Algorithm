#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
vector<int> maxi;

int increasing(int n) {
	maxi.emplace_back(0);
	for (int i = 1; i <= n; i++) {
		int counta = 0;
		for (int j = 1; j <= i; j++) {
			if (v[i] > v[j]) {
				counta = max(maxi[j], counta);
			}
		}
		maxi.emplace_back(counta+1);
	}
	return *max_element(maxi.begin(),maxi.end());
}

int main(void) {
	int n;
	cin >> n;
	v.emplace_back(0);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.emplace_back(x);
	}
	cout << increasing(n);
	return 0;
}
