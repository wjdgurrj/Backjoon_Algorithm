#include<iostream>

using namespace std;

int d[1001];

int dp(int n) {
	if (n == 1) return 1;
	if (n == 2) return 3;
	if (d[n] != 0)
		return d[n];
	return d[n] = (dp(n - 1) + 2*dp(n - 2))%10007;
}
// 꼬아내면 매우 어려워 질 수 있는 문제
//충분히 깊게 이해 후 점화식 만든 다음에
//문제 풀기.
int main(void)
{
	int x;
	cin >> x;
	cout << dp(x);
}
