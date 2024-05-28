#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int dp[105][105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string a, b, c;
	cin >> a >> b >> c;
	
	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 1; j <= b.size(); j++)
		{
			for (int k = 1; k <= c.size(); k++)
			{
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else
					dp[i][j][k] = max({ dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1] });
			}
		}
	}

	cout << dp[a.size()][b.size()][c.size()];


	
	return 0;
}
