#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

priority_queue<long long int,vector<long long int>,greater<long long int>> pq;

vector<pair<long long int, long long int>> v;


int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long int start, end;
		cin >> start >> end;
		v.push_back({ start,end });
	}
	sort(v.begin(), v.end());

	pq.push(v[0].second);
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (pq.top() <= v[i].first) {// 끝나는 시간이 시작시간보다 크거나 같으면, 즉 같은 강의실을 쓸 수 있으니
			pq.pop(); // 앞에 시간 빼주고
			pq.push(v[i].second); // 뒤에꺼 푸쉬
		}
		else {
			pq.push(v[i].second); // 강의실을 같이 쓰지 못하니
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
