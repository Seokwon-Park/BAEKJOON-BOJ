// 풀이를 참고함.
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int dp[100005][5][5];

int func(int a, int b)
{
	if (a == 0) return 2;
	if (a == b) return 1;
	if (abs(a - b) == 1 || abs(a-b) == 3) return 3;
	if (abs(a - b) == 2)return 4;
	return INF;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v(1, 0);
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)break;
		v.push_back(n);
	}

	fill_n(&dp[0][0][0], sizeof(dp) / sizeof(int), INF);
	dp[0][0][0] = 0;
	for (int i = 1; i < v.size(); i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			for (int k = 0; k <= 4; k++)
			{
				int jton = func(j, v[i]);
				int kton = func(k, v[i]);
				dp[i][v[i]][k] = min(dp[i][v[i]][k], dp[i - 1][j][k] + jton);
				dp[i][j][v[i]] = min(dp[i][j][v[i]], dp[i - 1][j][k] + kton);
			}
		}
	}

	int ans = INF;
	for (int j = 0; j <= 4; j++)
	{
		for (int k = 0; k <= 4; k++)
		{
			ans = min(ans, dp[v.size() - 1][j][k]);
		}
	}
	cout << ans;

	return 0;
}
