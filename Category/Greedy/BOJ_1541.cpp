#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
vector<int> v;
vector<int> minus1;
int main(void) {
	string s;
	cin >> s;
	bool tf = false;
	v.emplace_back(0);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			v.emplace_back(i + 1);
		}if (s[i] == '-'){
			tf = true;
			minus1.emplace_back(i + 1);
		}
	}
	v.emplace_back(s.size());
	int result = 0;
	if (tf == false) {
		for (int i = 0; i < v.size() - 2; i++) {
			result += stoi(s.substr(v[i], v[i + 1] - v[i] - 1));
		}
		result += stoi(s.substr(v[v.size()-2], v[v.size()-1] - v[v.size()-2] ));
	}
	else {
		int ans = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i] == minus1[0]) {
				ans = i;
				break;
			}
			result += stoi(s.substr(v[i], v[i + 1] - v[i] - 1));
		}
		for (int i = ans; i < v.size() - 2; i++) {
			result -= stoi(s.substr(v[i], v[i + 1] - v[i] - 1));
		}
		result -= stoi(s.substr(v[v.size() - 2]));
	}
	cout << result << '\n';
	return 0;
}
