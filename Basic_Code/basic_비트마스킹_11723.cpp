#include<iostream>
#include<bitset>
#include<string>

using namespace std;

int M;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M;
	unsigned int result = 0x000000;
	for (int i = 0; i < M; i++) {
		string s; int n;
		cin >> s;
		if (s == "empty"){
			result = 0x000000;
		}
		else if (s == "all") {
			result = 0xffffff;
		}
		else {
			cin >> n;
			if (s == "add") {
				result = result | (1 << n);
			}
			else if (s == "check") {
				if (result & (1 << n)) {
					cout << 1 << '\n';
				}
				else {
					cout << 0 << '\n';
				}
			}
			else if (s == "remove") {
				result = result & ~(1 << n);
			}
			else {
				result = result ^ (1 << n);
			}
		}
	}
}
int main(void) {
	init();
	return 0;
}
