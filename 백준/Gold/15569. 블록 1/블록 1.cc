#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int dp[10005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	// dp[1] = 1;
	//dp[2] = 2; // 1,1 2
	// dp[3] = 4; 1,2/ 1,1,1/ 2,1/ 3

	// 일단 NxN을 채우는 경우의 수를 고려하자. 이걸 나중에 90도 회전해서 가로인 상태로 넣을 블럭이라고 가정한다.
	for (int i = 1; i <= n; i++) 
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++) 
		{
			dp[i] += dp[i-j];
			dp[i] %= 1999;
		}
	}
	int rotate = dp[n] - 1; // 여기서 -1을 해주는 이유는 NxN블럭의 경우는 돌려도 똑같기 때문에 중복된다.
	// 그래서 이 블럭은 뺀다.
	dp[n] += rotate;// dp[n]에 rotate한 블럭을 넣는 경우의 수를 더해준다.
	dp[n] %= 1999;


	//이제 같은 방식으로 n+1부터 채워주기 시작하자.
	for (int i = n+1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++) // 여기서부터는 dp[i-1]에 1xN을 붙이는 경우의 수부터 dp[i-N]까지 해주면 된다.
		//근데 i-N의 경우는 N*N블럭을 붙일 수 있는 경우의 수가 회전시킨 경우로 더 추가 할 수있음
		// NxN(1개)에 위의 rotate를 더해서 dp[i-N] * (rotate + 1)만큼의 경우의 수가 나온다 
		// 이걸 더해줘야된다.
		{
			if (j == n)
			{
				dp[i] += dp[i - j] * (rotate+1);
			}
			else
			{
				dp[i] += dp[i - j];
			}
			dp[i] %= 1999;
			
		}
	}
	cout << dp[m];

	return 0;
}
