#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int dp[1005][25];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, n;
	cin >> c >> n;

	vector<pii> v;

	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < c + 1; j++)
		{
			dp[j][i] = INF;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int cost, val;
		cin >> cost >> val;
		v.push_back({ cost,val });

	}

	for (int i = 1; i <= n; i++)
	{
		auto [cost, val] = v[i - 1];
		for (int j = 1; j <= c; j++)
		{
			dp[j][i] = dp[j][i - 1];
			int k = 0;
			while (1)
			{
				if (val * k >= j)
				{
					dp[j][i] = min(dp[j][i], cost * k);
					break;
				}
				else
				{
					dp[j][i] = min(dp[j][i], dp[j - k * val][i - 1] + k * cost);
				}
				k++;
			}
		}
	}

	cout << dp[c][n];



	return 0;
}
