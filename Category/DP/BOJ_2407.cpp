#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string d[101][101];
int N, M;
string summation(string n, string m) {
	int sum = 0;
	string value;
	while (!n.empty() || !m.empty() || sum) {
		if (!n.empty()) {
			sum += n.back() - '0';
			n.pop_back();
		}
		if (!m.empty()) {
			sum += m.back() - '0';
			m.pop_back();
		}
		value.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(value.begin(), value.end());
	return value;
}
string dp(int n, int m){
	if (n == m || m == 0) {
		return "1";
	}
	if (d[n][m] != "") {
		return d[n][m];
	}
	return d[n][m] = summation(dp(n - 1, m - 1), dp(n - 1, m));
}
int main(void) {
	cin >> N >> M;
	cout << dp(N, M);
	return 0;
}
