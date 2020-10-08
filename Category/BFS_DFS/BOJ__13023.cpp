#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<int> people[2001];
int cnt = 0;
bool visit[2001];
int result = 0;
void dfs(int n) {
	if (cnt == 4) { 
		result = 1;
		
	}
	visit[n] = true;
	for (int i = 0; i < people[n].size(); i++) {
		int next = people[n][i];
		if (visit[next] == false ) {
			cnt++;
			dfs(next);
			}
		if (result == 1) {
			return;
		}
	}
	visit[n] = false;
	cnt--;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		people[num1].emplace_back(num2);
		people[num2].emplace_back(num1);
	}
	for (int i = 0; i < n; i++) {
			memset(visit, false, sizeof(visit));
			cnt = 0;
			dfs(i);
			if (result == 1) {
				cout << result << endl;
				return 0;
			}
		}
	cout << result << endl;

	return 0;
}
