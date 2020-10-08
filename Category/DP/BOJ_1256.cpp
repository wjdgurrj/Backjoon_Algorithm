#include <iostream>
#include <string>

using namespace std;

int N, M, K;
long long d[102][102];
string result;
void dp(int a, int z, long long length)
{
	if (a == 0)
	{ // a가 0개면 남은 z 다 이어주기
		for (int i = 0; i < z; i++)
		{
			result += 'z';
		}
		return;
	}
	if (z == 0)
	{ // ㅋ가 0개면 남은 a 다 이어주기
		for (int i = 0; i < a; i++)
		{
			result += 'a';
		}
		return;
	}
	if (d[a - 1][z] >= length) // 구하고자 하는 길이가 a가 하나 부족한 케이스보다 작거나 같으면 a 추가
	{
		result += 'a';
		dp(a - 1, z, length);
	}
	else //구하고자 하는 길이가 a가 하나 부족한 케이스 보다 크면 z 추가 , 길이는 length - d[a-1][z]
	{
		result += 'z';
		dp(a, z - 1, length - d[a - 1][z]);
	}
}
int main(void)
{
	cin >> N >> M >> K;
	d[1][1] = 2; // az, za 두가지 케이스
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (i == 0 || j == 0)
			{ // a , z 갯수가 1개씩이면 하나밖에 없으니 저장
				d[i][j] = 1;
				continue;
			}
			if (d[i + 1][j] <= 1000000000)
				d[i + 1][j] = d[i][j] * (i + j + 1) / (i + 1);
			else
			{
				d[i + 1][j] = 1000000001;
			}
			
			if (d[i][j + 1] <= 1000000000)
				d[i][j + 1] = d[i][j] * (i + j + 1) / (j + 1);
				else
				{
					d[i][j+1] = 1000000001;
				}
				
		}
	}

	if (d[N][M] < K)
	{
		cout << -1;
		return 0;
	}
	dp(N, M, K);
	cout << result;
	return 0;
}
