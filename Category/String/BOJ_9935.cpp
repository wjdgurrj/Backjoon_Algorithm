#include<iostream>
#include<string>

using namespace std;

char result[1000001];

int main(void) {
	string s;
	string bomb;
	int idx = 0;
	cin >> s >> bomb;
	for (int i = 0; i < s.length(); i++) {
		result[idx] = s[i];
		idx++;
		int size = bomb.length() - 1;
		if (s[i] == bomb[size]) {
			bool confirm = true;
			int idx2 = idx - bomb.length();
			for (int j = idx - 1; j >= idx2; j--) {
				if (result[j] == bomb[size]) {
					size--;
					continue;
				}
				else {
					confirm = false;
					break;
				}
			}
			if (confirm == true) {
				idx -= bomb.length();
			}
		}
	}
	if (idx == 0) {
		cout << "FRULA";
	}
	else {
		for (int i = 0; i < idx; i++) {
			cout << result[i];
		}
	}
	
	return 0;
}
