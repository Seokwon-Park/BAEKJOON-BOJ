#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll dp[10005][4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;

	dp[1][1] = 1; // 1
	dp[2][1] = 1; // 1+1, 2
	dp[2][2] = 1; // 1+1, 2
	dp[3][1] = 1;  // 1+1+1, 1+2, 3
	dp[3][2] = 1;  // 1+1+1, 1+2, 3
	dp[3][3] = 1;  // 1+1+1, 1+2, 3

	// 오름차순 정렬이 되도록 만들면 중복을 거를 수 있고 이렇게 만든다고 생각하면
	// +1이 붙을 수 잇는 곳은 합으로 나타내는 방법이 1로 끝나는 경우 뿐이다.
	// +2는 1로 끝나는 식이나 2로 끝나는 식에 붙일 수 있다.
	// +3도 동일. 
	for (int i = 4; i <= 10000; i++)
	{
		dp[i][1] += dp[i - 1][1];
		dp[i][2] += dp[i - 2][1];
		dp[i][2] += dp[i - 2][2];
		dp[i][3] += dp[i - 3][1];
		dp[i][3] += dp[i - 3][2];
		dp[i][3] += dp[i - 3][3];
	}

	while (tc--)
	{
		int n;
		cin >> n;
		cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
	}

	return 0;
}