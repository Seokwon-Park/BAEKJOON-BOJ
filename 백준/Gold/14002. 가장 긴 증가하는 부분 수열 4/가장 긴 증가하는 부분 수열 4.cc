
#include <bits/stdc++.h>

using namespace std;

int dp[1005];
int pre[1005];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}

	for(int i = 2; i <=n; i++)
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					pre[i] = j;
				}
			}
		}

	int ix = max_element(dp, dp + n + 1) - dp;
	cout << dp[ix] << '\n';
	int cur = pre[ix];
	vector<int> p;
	p.push_back(arr[ix]);
	while (cur != 0)
	{
		p.push_back(arr[cur]);
		cur = pre[cur];
	}
	
	for (auto it = p.rbegin(); it != p.rend(); it++)
	{
		cout << *it << ' ';
	}


	return 0;
}

