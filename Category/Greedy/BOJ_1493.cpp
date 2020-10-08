#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;
int l, w, h ,n , result;
vector<pair<int, int>> v;
bool fault = true;
void solve(int x, int y, int z) {
	if (fault == false) {
		return;
	}
	if (x == 0 || y == 0 || z == 0) {
		return;
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		if (x >= v[i].first &&  y >= v[i].first &&  z >= v[i].first && v[i].second > 0) {
			v[i].second--;
			result++;
			solve(x , y , z - v[i].first); // 위의 남은 공간 
			solve(v[i].first, y - v[i].first, v[i].first); // 밑에부분중 한쪽 공간 
			solve(x - v[i].first, y , v[i].first); //나머지 한쪽 공간
			return;
		}
	}
	fault = false;
}

int main(void) {
	cin >> l >> w >> h >> n;
	for (int i = 0; i < n; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		v.push_back({ pow(2,num1),num2 });
	}
	sort(v.begin(), v.end());
	solve(l, w, h);
	if (fault == false) {
		cout << -1;
	}
	else {
		cout << result;
	}
	return 0;
}
