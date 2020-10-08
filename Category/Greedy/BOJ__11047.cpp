#include<iostream>
#include<vector>

using namespace std;

vector<int> v;
int main(void) {
	int N, K;
	cin >> N >> K;
	int index = N - 1;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.emplace_back(num);
	}
	for (int i = 0; i < N; i++) {
		if (v[i] >= K) {
			index = i;
			break;
		}
	}
	int result = 0; 
	while (K > 0) {
		int num = K / v[index];
		result += num;
		K -= num * v[index];
		index--;
	}
	cout << result;
	return 0;
}
