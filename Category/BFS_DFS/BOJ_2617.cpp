#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

vector<int> v1[100];
vector<int> v2[100];
bool visit[100];
int arr[100][2];
int slave_dfs(int n) {
	int cnt1 = 1;
	visit[n] = true;
	for (int i = 0; i < v1[n].size(); i++) {
		int next = v1[n][i];
		//하위노드 갯수
		if (visit[next]== false) {
			cnt1 += slave_dfs(next);
		}
	}
	return cnt1;
}
int master_dfs(int n) {
	int cnt2 = 1;
	visit[n] = true;
	for (int i = 0; i < v2[n].size(); i++) {
		int next = v2[n][i];
		//하위노드 갯수
		if (visit[next] == false) {
			cnt2 += master_dfs(next);
		}
	}
	return cnt2;
}
int main(void) {
	int n, m, result = 0;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		v1[num2].emplace_back(num1);
		v2[num1].emplace_back(num2);
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		arr[i][0] = slave_dfs(i);
		memset(visit, false, sizeof(visit));
		arr[i][1] = master_dfs(i);
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i][0] > (n + 1) / 2) {
			result++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i][1] > (n + 1) / 2) {
			result++;
		}
	}
	cout << result << '\n';
	return 0;
	
}
