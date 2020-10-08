#include<iostream>
#include<queue>

using namespace std;

queue<int> q;
bool visit[100001];
int arr[100001];

void bfs(int start, int end) {
	int current;
	q.push(start);
	while (!q.empty()) {
		current = q.front();
		q.pop();
		if (current == end) {
			return;
		}
		if (current * 2 <= 100000 && visit[current * 2] == false) {
			q.push(current * 2);
			arr[current * 2] = arr[current];
			visit[current * 2] = true;
		}
		if (current - 1 >= 0 && visit[current - 1] == false) {
			q.push(current - 1);
			arr[current - 1] = arr[current] + 1;
			visit[current - 1] = true;
		}
		if (current + 1 <= 100000 && visit[current + 1] == false) {
			q.push(current + 1);
			arr[current + 1] = arr[current] + 1;
			visit[current + 1] = true;
		}
		
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;
	bfs(n, m);
	cout << arr[m] << endl;
	return 0;
}
