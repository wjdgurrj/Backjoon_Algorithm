#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n;
vector<int> v[100001];
vector<string> result;
int main(void) {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		v[num1].emplace_back(num2);
		v[num2].emplace_back(num1);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int t, k;
		cin >> t >> k;
		if (t == 1) {
			if (v[k].size() == 1) {
				result.emplace_back("no");
			}
			else {
				result.emplace_back("yes");
			}
		}
		else {
			result.emplace_back("yes");
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	return 0;
}
