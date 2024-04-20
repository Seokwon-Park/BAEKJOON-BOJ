#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

bool dp[55][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, s, m;
	cin >> n >> s >> m;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	dp[0][s] = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (dp[i-1][j])
			{
				if (j - v[i] >= 0)
				{
					dp[i][j - v[i]] = true;
				}
				if (j + v[i] <= m)
				{
					dp[i][j + v[i]] = true;
				}

			}
		}
	}

	for (int i = m; i >= 0; i--)
	{
		if (dp[n][i])
		{
			cout << i;
			return 0;
		}
	}

	cout << -1;


	return 0;
}