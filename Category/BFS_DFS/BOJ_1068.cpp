#include<iostream>
#include<vector>

using namespace std;

vector<int> v[50];
bool visit[50];
int result;

void dfs(int n) {
	visit[n] = true;
	int cnt = 0;
	for (int i = 0; i < v[n].size(); i++) {
		int next = v[n][i];
		if (visit[next] == false) {
			dfs(next);
			cnt++;
		}
		
	}
	if (cnt == 0) {
		result++;
	}
}

int main(void) {
	int num, start,cut;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int n;
		cin >> n;
		if (n == -1) {
			start = i;
		}
		else {
			v[n].emplace_back(i);
		}
	}
	cin >> cut;
	if (cut == start) {
		cout << 0 << endl;
		return 0;
	}
	dfs(cut);
	result = 0;
	dfs(start);
	cout << result << endl;
	return 0;
}
