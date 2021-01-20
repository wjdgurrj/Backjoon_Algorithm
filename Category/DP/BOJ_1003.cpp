#include<iostream>
#include<string>

using namespace std;
int f[20];
int main(void) {
	int x;
	cin >> x;
	f[0] = 1;
	f[1] = 0;
	for (int i = 2; i <= 41; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	int n;
	for (int i = 0; i < x; i++) {
		cin >> n;
		cout << f[n] << ' ' << f[n + 1] << endl;
		
	}
	
}
