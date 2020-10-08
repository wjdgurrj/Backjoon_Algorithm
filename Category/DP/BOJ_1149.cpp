#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int, pair<int, int>>> house;
vector<int> R,G,B;

int painting(int n) {
	R.emplace_back(0);
	G.emplace_back(0);
	B.emplace_back(0);
	for (int i = 1; i <= n; i++) {
		R.emplace_back(min(G[i-1],B[i-1])+house[i].first);
		G.emplace_back(min(R[i - 1], B[i - 1]) + house[i].second.first);
		B.emplace_back(min(G[i - 1], R[i - 1]) + house[i].second.second);
	}
	int minimum;
	minimum = min(min(R[n], G[n]), B[n]);
	return minimum;
}


int main(void) {
	int n;
	cin >> n;
	house.emplace_back(make_pair(0, make_pair(0, 0)));
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		house.emplace_back(make_pair(a, make_pair(b, c)));
	}
	cout << painting(n) << endl;
	return 0;
}
