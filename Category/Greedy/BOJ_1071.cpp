#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
	int N, tmp, tmp2;
	bool inclined = false;
	bool same = true;
	bool checked = false;
	cin >> N;
	vector<int> nums;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		nums.push_back(tmp);
	}

	sort(nums.begin(), nums.end());

	while (inclined == false) {
		same = true;
		checked = false;

		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] + 1 == nums[i + 1]) {
				checked = true;
				if (i == nums.size() - 2) {
					tmp = nums[nums.size() - 1];
					nums.erase(nums.begin() + i + 1);
					nums.insert(nums.begin() + i, tmp);
				}
				else {
					for (int j = i + 2; j < nums.size(); j++) {
						if (nums[i + 1] < nums[j]) {
							same = false;

							tmp = nums[i + 1];
							tmp2 = nums[j];

							nums.erase(nums.begin() + j);
							nums.insert(nums.begin() + j, tmp);
							nums.erase(nums.begin() + i + 1);
							nums.insert(nums.begin() + i + 1, tmp2);
							break;
						}
					}
					if (same == true) {
						tmp = nums[i + 1];
						nums.erase(nums.begin() + i + 1);
						nums.insert(nums.begin() + i, tmp);
						break;
					}
				}
				break;
			}
		}
		if (checked == false) {
			inclined = true;
		}
	}
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << ' ';
	}
	return 0;

}
