#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
parent를 전부 저장하게 되면은 메모리 초과가 나게 된다
해결책 : 2^k 의 부모들만 찾아 주면 된다.
그림 그려 논리를 파악해 보면은 쉽게 알 수 있다.
*/
vector<int> tree[100001];
int parent[100001][19];
int depth[100001];
vector<pair<int,int>> node;
int N, M;
bool visited[100001];

void init() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;
		tree[x].emplace_back(y);
		tree[y].emplace_back(x);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		node.push_back({ x,y });
	}
}

void dfs(int x) { // 해당 숫자의 depth와 첫번째 부모만 저장해둔다.
	for (int i = 0; i < tree[x].size(); i++) {
		if(!visited[tree[x][i]]){
			parent[tree[x][i]][0] = x;
			depth[tree[x][i]] = depth[x] + 1;
			visited[tree[x][i]] = true;
			dfs(tree[x][i]);
			visited[tree[x][i]] = false;
		}
	}
}

int main(void) {
	init();
	depth[1] = 0;
	visited[1] = true;
	dfs(1);
	for (int i = 0; i < 17; ++i) {
		for (int j = 2; j <= N; ++j) { // 2부터 N 까지 자기 부모 노드의 2^i번쨰 노드를 저장한다. 
			int k = parent[j][i];
			if (k != 0) {
				parent[j][i + 1] = parent[k][i];
			}
		}
	}
	for (int i = 0; i < M; i++) {
		int a = node[i].first;
		int b = node[i].second;
		int size;
		int idx = 0;
		if (depth[a] < depth[b]) { // 깊이가 깊은 값을 a로 둔다.
			swap(a, b);
		}
		size = depth[a] - depth[b];
		while (size) { // 깊이를 맞추어 준다.
			if (size % 2) { // a가 더 깊으므로 a는 자기 부모노드를 가지면서 b와 높이를 맞춘다.
				a = parent[a][idx];
			}
			idx++;
			size /= 2;
		}
		if (a == b) { //a와 b가 같다면 현재 a나 원래 b가 공통 부모노드 일 것이다.
			cout << a << '\n';
		}
		else {
			for (int j = 17; j >= 0; j--) {
				if (parent[a][j] != parent[b][j]) { //a와 b의 부모가 같지 않다면 그 부모들로 각각 갱신해 준다.
					// 한번 부모가 같게 되면은 그 이후로는 쭉 같을 것이다.
					a = parent[a][j];
					b = parent[b][j];
				}
			}
			// 그 a의 첫번째 부모가 공통 부모가 될 것이므로 a를 갱신해준다.
			a = parent[a][0];
			cout << a << '\n';
		}
	}

	return 0;
}
