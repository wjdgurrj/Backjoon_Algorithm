#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
typedef struct {
	int value = 0;
	int cnt = 0;
} Multitap;

vector<int> v,tap;
Multitap multitap[101];
int idx; // 뽑는 횟수 
bool visit[101]; 

int main(void) {
	int N, K;
	cin >> N >> K;
	v.emplace_back(0);
	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		v.emplace_back(num);
		multitap[num].cnt++; // 총 몇 번 꽃아야 하는지 판단하기위해
	}
	int result = 0; // 멀티탭에 꽃혀있는 전자기기의 갯수
	for (int i = 1; i <= K; i++) {
		if (result < N && multitap[v[i]].value == 0) { // 꽃을 수 있는 공간이 남아 있고, 안꽃혀 있을때
			multitap[v[i]].value = 1;
			tap.emplace_back(v[i]);
			result++;
			multitap[v[i]].cnt--;
			continue;
		}
		else if (result <= N && multitap[v[i]].value == 1) { // 이미 꽃혀 있을 때
			multitap[v[i]].cnt--;
			continue;
		}
		else if (result == N && multitap[v[i]].value == 0) { // 뺴고 새로 꽃아야 할 때
			int visited = 0;
			vector<int> chk;
			vector<int> ::iterator iter = tap.begin();
			memset(visit, false, sizeof(visit));
			for (int j = 0; j < N; j++) { // 코드에 꽃혀 있는 전자기기 중 뒤에 다시 나오지 않는 경우
				if (multitap[tap[j]].cnt == 0) {
					iter += j;
					multitap[tap[j]].value = 0;
					tap.erase(iter);
					visited = 1;
					break;
				}
			}
			if (visited == 1) { // 카운트가 0인 코드가 나올 경우
				tap.emplace_back(v[i]);
				multitap[v[i]].cnt--;
				multitap[v[i]].value = 1;
				idx++;
				continue;
			}
			else { // 연결된 모든 코드가 뒤에 다시 나올 경우
				for (int j = i + 1; j <= K; j++) {
					if (multitap[v[j]].value == 1) { //연결되어 있을 때 맨 나중에 나오는 코드 찾기
						if (visit[v[j]] == false) {
							visit[v[j]] = true;
							chk.emplace_back(v[j]);
						}
					}
					if (chk.size() == N) {
						break;
					}
				}
				for (int j = 0; j < N; j++) {
					if (tap[j] == chk[chk.size() - 1]) {
						iter += j;
						multitap[tap[j]].value = 0;
						tap.erase(iter);
						break;
					}
				}
				tap.emplace_back(v[i]);
				idx++;
				multitap[chk[chk.size() - 1]].value = 0;
				multitap[v[i]].cnt--;
				multitap[v[i]].value = 1;
			}
		}
	}
	cout << idx;
	return 0;
}
