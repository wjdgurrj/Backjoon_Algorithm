#include<iostream>

using namespace std;
// 시간초과 
#define maximum 1000000000;

int main(void) {
	long long int num;
	long long int wincase;
	long long int counta = 0;
	cin >> num >> wincase;
	long long int winPercent = (wincase * 100 / num);
	long long int changePercent;
	int low = 0;
	int high = maximum;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		changePercent = ((wincase + mid) * 100 / (num + mid));
		if (winPercent >= changePercent)
		{
			counta = mid + 1;
			low = mid + 1;
		}
		else
			high = mid - 1;

		if (winPercent >= 99)
		{
			cout << -1;
			return 0;
		}
	}
	/*
	long long int num;
	long long int wincase;
	long long int counta = 0;
	cin >> num >> wincase;
	long long int winPercent = (wincase * 100 / num);
	long long int changePercent = winPercent;
	while (changePercent == winPercent){
		num++; wincase++;
		changePercent = (wincase * 100 / num);
		counta++;
		if (winPercent >= 99)
		{
			cout << -1;
			return 0;
		}
	}
	*/
	cout << counta;
	return 0;
}
