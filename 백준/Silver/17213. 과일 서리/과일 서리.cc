#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int dp[35][15];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	if (n == m)
	{
		cout << 1;
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][k];
			}
		}
	}

	// m개의 과일을 훔쳐야되는데 하나씩은 훔쳐야 된다고 했으므로 n개를 종류별로 이미 훔쳤다고 가정한다.
	cout << accumulate(dp[m-n], dp[m-n] + n + 1, 0);


	return 0;
}

