#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int day[105];
int dp[105][6]; // 0 - xx1, 1 - xx2, 2 - xx3, 3 - x11, 4 - x22, 5 - x33



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		day[a] = b;
	}

	if (day[1] == 1)
	{
		dp[1][0] = 1;
	}
	else if (day[1] == 2)
	{
		dp[1][1] = 1;
	}
	else if (day[1] == 3)
	{
		dp[1][2] = 1;
	}
	else
	{
		dp[1][0] = 1;
		dp[1][1] = 1;
		dp[1][2] = 1;
	}


	for (int i = 2; i <= n; i++)
	{
		if (day[i] == 1)
		{
			dp[i][0] = dp[i-1][1] + dp[i-1][2]+dp[i-1][4]+dp[i-1][5];
			dp[i][0] %= 10000;
			dp[i][3] = dp[i - 1][0];
		}
		else if(day[i] == 2)
		{
			dp[i][1] = dp[i - 1][0] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][5];
			dp[i][1] %= 10000;
			dp[i][4] = dp[i - 1][1];
		}
		else if(day[i] == 3)
		{
			dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4];
			dp[i][2] %= 10000;
			dp[i][5] = dp[i - 1][2];
		}
		else
		{
			dp[i][0] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][5];
			dp[i][0] %= 10000;
			dp[i][1] = dp[i - 1][0] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][5];
			dp[i][1] %= 10000;
			dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4];
			dp[i][2] %= 10000;
			dp[i][3] = dp[i - 1][0];
			dp[i][4] = dp[i - 1][1];
			dp[i][5] = dp[i - 1][2];
		}
	}

	cout << accumulate(dp[n], dp[n] + 6, 0)%10000;
	

	return 0;
}