#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dp[105][105];
string GetLCS(string a, string b, int i, int j)
{
	if (i == 0)
	{
		return b.substr(0, j);
	}
	else if (j == 0)
	{
		return a.substr(0, i);
	}
	else if (a[i - 1] == b[j - 1])
	{
		return GetLCS(a, b, i - 1, j - 1) + a[i - 1];
	}

	if (dp[i][j - 1] >= dp[i - 1][j])
	{
		return GetLCS(a, b, i, j - 1) + b[j - 1];
	}
	else
	{
		return GetLCS(a, b, i - 1, j) + a[i - 1];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	while (cin >> a >> b)
	{
		int as = a.size();
		int bs = b.size();
		for (int i = 0; i <= as; i++)
		{
			for (int j = 0; j <= bs; j++)
			{
				if (i == 0 || j == 0)
				{
					dp[i][j] = 0;
				}
				else if (a[i - 1] == b[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << GetLCS(a, b, as, bs) << '\n';

	}


	return 0;
}