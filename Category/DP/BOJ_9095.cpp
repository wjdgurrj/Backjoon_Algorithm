#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v;
int n;
int d[11];
int a[11];
int sum;
int adddd(int n) {
	if (n == 1) return 1;
	if (n == 2)return 2;
	if (n == 3)return 4;
	if (d[n] != 0) return d[n];
	d[n] = adddd(n-1)+adddd(n-2)+adddd(n-3);
	int result = d[n];
	return result;
}

int main(void) {
	int x;
	cin >> x;
	for (int i = 0; i < x; i++) {
		cin >> n;
		a[i] = adddd(n);
	}
	for (int i = 0; i < x; i++) {
		cout << a[i] << endl;
	}

}
