#include<iostream>
#include<regex>
#include<vector>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	regex re("(100+1+|01)+");
	if ((regex_match(s, re))) {
		cout << "SUBMARINE";
	}
	else {
		cout << "NOISE";
	}
	return 0;
}
