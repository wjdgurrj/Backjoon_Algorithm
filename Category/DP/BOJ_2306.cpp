#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string dna;
int d[501][501];
// 2번 조건, 3번 조건

void init() {
	cin >> dna;
}

int dp() {
	for (int i = 1; i < dna.size(); i++) {
		for (int j = 0; j + i < dna.size(); j++) {
			int last = j + i;
			if ((dna[j] == 'a' && dna[last] == 't') || (dna[j] == 'g' && dna[last] == 'c')) {//2번조건
				d[j][last] = d[j + 1][last - 1] + 2;//2번 조건에 해당이 되면 안에 있는 값 + 2
			}
			for (int k = j; k < last; k++){// 3번 조건
				d[j][last] = max(d[j][last], d[j][k] + d[k + 1][last]); 
			}
		}
	}
	return d[0][dna.size() - 1];
}

int solution() {
	init();
	return dp();
}
int main(void) {
	cout << solution();
	return 0;
}
