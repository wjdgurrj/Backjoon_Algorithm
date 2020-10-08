#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

queue<int> q;
int v[100001] = { 0, };
int arr[100001] = {0, };
int start, department;
int sibling(int start, int department) {
	int current;
	q.push(start);
	while (!q.empty()) {
		current = q.front();
		if (current == department) {
			return arr[current];
		}
		q.pop();
		if (current - 1 >= 0 && !v[current - 1]) {
			q.push(current - 1);
			arr[current - 1] = arr[current] + 1;
			v[current-1] = true;
		}
		if (current + 1 <= 100000 && !v[current + 1] ) {
			q.push(current + 1);
			arr[current + 1] = arr[current] + 1;
			v[current+1] = true;
		}
		if (current*2 <= 100000 && !v[current*2] ) {
			q.push(current*2);
			arr[current*2] = arr[current] + 1;
			v[current*2] = true;
		}
	}
}

int main(void) {
	cin >> start >> department;
	cout << sibling(start, department);
	return 0;
}
