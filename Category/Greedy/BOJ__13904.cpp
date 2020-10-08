#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int>> v;
bool visit[1001];

int main(void) {
	int n;
	cin >> n ;
	for (int i = 0; i < n; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		v.push_back({ num1,num2 });
	}
	sort(v.begin(), v.end());
	int date = v[v.size() - 1].first;
	int result = 0;
	while (date != 0) {
		int max_element = 0;
		int idx = v.size() - 1;
		for (int j = v.size() - 1; j >= 0; j--) {
			if (v[j].first < date) {
				break;
			}
			else if (v[j].first >= date && visit[j] == false) {
				if (max_element < v[j].second) {
					idx = j;
				}
				max_element = max(max_element, v[j].second);
			}
		}
		visit[idx] = true;
		date--;
		result += max_element;
	}
	cout << result;
	return 0;
}
