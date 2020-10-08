#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long int> v;

int main(void) {
	int num, counta;
	cin >> num;
	v.emplace_back(0);
	v.emplace_back(1);
	v.emplace_back(1);
	v.emplace_back(1);
	for (int i = 4; i <= 100; i++) {
		v.emplace_back(v[i - 2] + v[i - 3]);
	}
	for (int i = 0; i < num; i++)
	{
		int x;
		cin >> x;
		cout << v[x] << endl;
	}
	return 0;
}
