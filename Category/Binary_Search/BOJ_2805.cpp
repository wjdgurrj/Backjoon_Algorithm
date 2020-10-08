#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> tree;


int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		tree.emplace_back(num);
	}
	sort(tree.begin(), tree.end());
	long long int maximum = 0;
	long long int low = 0;
	long long int high = tree[n- 1];
	long long height = 0;
	while (low <= high) {
		long long sum = 0;
		long long int mid = (low + high) / 2;
		for (int i = 0; i < n; i++) {
			if (tree[i] - mid > 0) {
				sum += tree[i] - mid;
			}
		}
		if (sum >= m) {
			low = mid + 1;
			height = mid;
		}
		else {
			high = mid - 1;
		}
	}
	
	cout << height << '\n';
	return 0;
}
