#include<iostream>
#include<vector>
#include<string>

using namespace std;

int d[1001];

int tyle(int x) {
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (d[x] != 0) return d[x];
	int result = 3 * tyle(x-2);
	for (int i = 3; i <= x; i++) {
		if (x % 2 == 0)
			result += 2 * tyle(x - i);
	}
	return d[x] = result;
}

int main()
{
	int x;
	cin >> x ;
	cout << tyle(x) << endl;

	return 0;
}
