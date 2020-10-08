#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

vector<int> v[101];
bool visit[101];
pair<int, int> p;
int result[101];
int cnt;
void virus(int i) {
	visit[i] = true;
	for (int j = 0; j < v[i].size(); j++) {
		int next = v[i][j];
		if (!visit[next]) {
			cnt++;
			virus(next);
		}
	}
}


int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> p.first >> p.second;
		v[p.first].emplace_back(p.second);
		v[p.second].emplace_back(p.first);
	}
	virus(1);
	cout << cnt << endl;
	
	return 0;
}
