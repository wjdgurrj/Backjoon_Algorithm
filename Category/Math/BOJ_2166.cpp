#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int N;
vector<pair<double, double>> v;
double A, B;
double result;

double cross(double x1, double x2, double y1, double y2) {
	return x1 * y2 - x2 * y1;
}

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
}

void solve() {
	for (int i = 1; i < v.size() - 1; i++) {
		A += cross(v[i].first - v[0].first, v[i].second - v[0].second, v[i + 1].first - v[0].first, v[i + 1].second - v[0].second) / 2;
	}
	printf("%.1f", abs(A));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	init();
	solve();
	return 0;
}
