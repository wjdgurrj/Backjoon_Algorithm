#include<iostream>
#include<algorithm>

using namespace std;
int computer[10000001];
int main(void) {
	unsigned long long n;
	cin >> n;
	unsigned long long sum = 1;
	for (int i = 0; i < n*n; i++) {
		long long num;
		cin >> num;
		sum += num;
		computer[num]++;
	}
	unsigned long long half_result = sum / 2;
	unsigned long long value = 0;
	unsigned long long index = 0;
	unsigned long long total = 0;
	while (value < half_result) {
		total += computer[index];
		value += n * n - total;
		index++;
	}
	cout << index  << '\n';
	
}
