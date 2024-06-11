#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int dp[101][10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> mv(n);
	vector<int> cv(n);
	for (int i = 0; i < n; i++)
	{
		int mm;
		cin >> mm;
		mv[i] = mm;
	}

	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		cv[i] = c;
	}

	for (int i = 1; i <= n; i++)
	{
		int mm = mv[i - 1];
		int c = cv[i - 1];
		for (int j = 0; j <= 10000; j++)
		{
			if (c <= j)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c] + mm);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	for (int j = 0; j <= 10000; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (dp[i][j] >= m)
			{
				cout << j;
				return 0;
			}
		}
	}

}
