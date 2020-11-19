#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> crane; // 크래인을 넣을 벡터
vector<int> box; // 박스를 넣을 벡터
int main(void) {
	int N, boxCnt; // 박스와 크래인의 갯수
	cin >> N; // 크래인의 갯수 입력
	for (int i = 0; i < N; i++) { // 크래인 용량 제한 입력
		int limit;
		cin >> limit;
		crane.emplace_back(limit);
	}
	cin >> boxCnt; // 박스의 갯수 입력
	for (int i = 0; i < boxCnt; i++) { // 박스의 무게 입력
		int weight;
		cin >> weight;
		box.emplace_back(weight);
	}
	sort(crane.begin(), crane.end(), greater<>()); // 크래인 내림차순 정렬
	sort(box.begin(), box.end(), greater<>()); // 박스 내림차순 정렬
	if (box[0] > crane[0]) { // 크래인에 박스를 담을 수 없으면, -1 출력
		cout << -1;
		return 0;
	}
	int result = 0; // 시간
	while (!box.empty()) { // 박스가 다 지워질 떄 까지
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < box.size(); j++) {
				if (crane[i] >= box[j]) {
					vector<int>::iterator iter = box.begin(); // begin iterator 생성
					box.erase(iter + j); // box 담았으면 지워주기.
					break; // 다음꺼 다음 크래인에 담아주기위해
				}
			}
		}
		result++; // 한번 옮겼으니 1초추가
	}
	cout << result;
	return 0;
}
