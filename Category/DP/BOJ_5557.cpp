#include<iostream>

using namespace std;
#define MAX 100+1

int n;
int num[MAX]={0,};
long table[MAX][21]={0,};

void input(){
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> num[i];
}

long dp(){
	table[0][num[0]]++;

	for(int i=1; i<n-1; i++){
		for(int j=0; j<21; j++){
			if(table[i-1][j]>0){
				if(j+num[i]<=20)
					table[i][j+num[i]] += table[i-1][j];
				if(j-num[i]>=0)
					table[i][j-num[i]] += table[i-1][j];
			}
		}
	}
	return table[n-2][num[n-1]];
}

int main(){
	input();
	cout << dp() <<endl;
	return 0;
}
