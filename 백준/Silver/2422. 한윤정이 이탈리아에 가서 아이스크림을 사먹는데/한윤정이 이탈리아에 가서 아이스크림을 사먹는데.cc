#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool isBan[205][205];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		isBan[a][b] = true;

	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			if (isBan[i][j]) continue;
			for (int k = j + 1; k <= n; k++)
			{
				if (isBan[i][k] || isBan[j][k]) continue;
				ans++;
			}
		}
	}
	cout << ans;

	return 0;
}