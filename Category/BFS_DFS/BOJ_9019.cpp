#include<iostream>
#include<string>
#include<queue>

using namespace std;
int d1, d2, d3, d4;
string bfs(int start, int department) {
	bool visit[10000] = { 0, };
	queue<pair<int, string>> q;
	q.push(make_pair(start,""));
	visit[start] = true;
	while (!q.empty()){
		pair<int,string> current = q.front();
		q.pop();
		if (current.first == department) {
			return current.second;
		}
		for (int i = 0; i < 4; i++) {
			int next;
			if (i == 0) {
				if (current.first * 2 > 9999) {
					next = (2 * current.first) % 10000;
				}
				else {
					next = current.first * 2;
				}
				if (visit[next] == false) {
					visit[next] = true; q.push(make_pair(next, current.second + "D"));
				}
			}
			if (i == 1) {
				next = current.first - 1;
				if (next < 0) {
					next = 9999;
				}
				if (visit[next] == false) {
					visit[next] = true; q.push(make_pair(next, current.second + "S"));
				}
			}
			if (i == 2) {
				d4 = current.first % 10;
				d3 = (current.first / 10) % 10;
				d2 = (current.first / 100) % 10;
				d1 = (current.first / 1000);
				next = d2 * 1000 + d3 * 100 + d4 * 10 + d1;
				if (visit[next] == false) {
					visit[next] = true; q.push(make_pair(next, current.second + "L"));
				}
			}
			if (i == 3) {
				d4 = current.first % 10;
				d3 = (current.first / 10) % 10;
				d2 = (current.first / 100) % 10;
				d1 = (current.first / 1000);
				next = d4 * 1000 + d1 * 100 + d2 * 10 + d3;
				if (visit[next] == false) {
					visit[next] = true; q.push(make_pair(next, current.second + "R"));
				}
			}
		}
	}
	return 0;
}

int main(void) {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		cout << bfs(num1, num2) << '\n';
	}
	return 0;
}
