#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> box;
vector<int> maxi;
int dp(int n) {
	for (int i = 0; i < n; i++) {
		int cnt = box[i];
		for (int j = 0; j <= i; j++) {
			if (box[i] > box[j]) {
				cnt = max(maxi[j]+box[i], cnt);
			}
		}
		maxi.emplace_back(cnt);
	}
	return *max_element(maxi.begin(), maxi.end());
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		box.emplace_back(num);
	}
	cout << dp(n);
	return 0;
}
