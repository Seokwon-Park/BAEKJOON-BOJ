#include <bits/stdc++.h>

using namespace std;

int dp[1005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	// i개일때 자기 차례인 사람이 이김?
	dp[1] = 1; // ㅇㅇ
	dp[2] = 0; // ㄴㄴ
	dp[3] = 1; // ㅇㅇ
	dp[4] = 1; // ㄴㄴ
	//dp[5] = ?   // 상근이가 1개 가져간 경우 dp[5-1], 3개 가져가면 dp[5-3], 4개 가져가면 dp[5-4], 
	// 창영이 차례에 dp[4], dp[2], dp[1] 이러면 dp[2]일때 창영이는 무조건 지기 때문에 상근이가 3개를 가져가면 그만임
	// 따라서 dp[i-1] dp[i-3] dp[i-4]가 모두 1인 경우여야 상근이가 뭘 고르던 창영이 턴에 이기게 된다.

	for (int i = 5; i <= n; i++)
	{
		for (int j : {1, 3, 4})
		{
			if (dp[i - j] == 0)// 상근이가 j개 가져감->
				//창영이 차례에 i-j개인데 하나라도 지는 경우 = 0이 있으면 상근이가 그 수를 두면 되기 때문에 창영이는 절대 못이김.
			{
				dp[i] = 1; 
				break; // for loop 깨줌
			}
			else
			{
				dp[i] = 0; // 만약 창영이가 지는 경우가 없으면 i번째 돌일때 상근이는 무조건 진다.
			}
		}
	}


	if (dp[n] == 1)
		cout << "SK";
	else
		cout << "CY";

	return 0;
}