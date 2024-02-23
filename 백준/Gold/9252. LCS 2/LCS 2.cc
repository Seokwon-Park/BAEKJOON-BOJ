#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];
string dpstr[1005][1005];
string a, b;


string func(int i, int j)
{
	if (i == 0 || j == 0)
	{
		return "";
	}
	if (a[i - 1] == b[j - 1])
		return func(i-1,j-1) + a[i - 1];
	if (dp[i][j-1] > dp[i-1][j])
		return func(i, j - 1);
	return func(i - 1, j);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b;

	for (int i = 1; i <= a.length(); i++)
	{
		for (int j = 1; j <= b.length(); j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	cout << dp[a.length()][b.length()] << '\n';
	cout << func(a.length(),b.length());


	return 0;
}
