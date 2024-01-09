#include <bits/stdc++.h>

using namespace std;

int dp[1000005];
int pre[1000005];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0 && i % 3 == 0)
		{
			int mini = min({ dp[i / 2], dp[i / 3], dp[i - 1] });
			if (mini == dp[i / 2])
			{
				dp[i] = dp[i / 2];
				pre[i] = i / 2;
			}
			else if (mini == dp[i / 3])
			{
				dp[i] = dp[i / 3];
				pre[i] = i / 3;
			}
			else
			{
				dp[i] = dp[i - 1];
				pre[i] = i - 1;
			}
			dp[i]++;
		}
		else if (i % 3 == 0)
		{
			if (dp[i / 3] < dp[i - 1])
			{
				dp[i] = dp[i / 3];
				pre[i] = i / 3;
			}
			else
			{
				dp[i] = dp[i - 1];
				pre[i] = i - 1;
			}
			dp[i]++;

		}
		else if (i % 2 == 0)
		{
			if (dp[i / 2] < dp[i - 1])
			{
				dp[i] = dp[i / 2];
				pre[i] = i / 2;
			}
			else
			{
				dp[i] = dp[i - 1];
				pre[i] = i - 1;
			}
			dp[i]++;
		}
		else
		{
			dp[i] = dp[i - 1] + 1;
			pre[i] = i - 1;
		}
	}

	cout << dp[n] << '\n';
	vector<int> path;
	path.push_back(n);
	int cur = pre[n];
	while (cur != 0)
	{
		path.push_back(cur);
		cur = pre[cur];
	}
	for (int i : path)
	{
		cout << i << ' ';
	}

	return 0;
}
