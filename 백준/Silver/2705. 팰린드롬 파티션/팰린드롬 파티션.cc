#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

ll dp[1005];
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 1000; i++)
	{
		//자기 자신은 무조건 재귀 펠린드롬
		if (i % 2 == 0)
		{
			for (int j = 0; j <= i; j += 2)
			{
				dp[i] += dp[(i - j) / 2];
			}
		}
		else
		{
			// i에서 x<i 인 짝수x의 경우의 수
			for (int j = 1; j <= i; j += 2)
			{
				dp[i] += dp[(i - j) / 2];
			}
		}
	}

	int t;
	cin >> t;
	while (t--)
	{
		int x;
		cin >> x;
		cout << dp[x] << '\n';
	}


	

	return 0;
}