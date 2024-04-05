#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int b[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int t = 0; t < n; t++)
	{
		int x, y;
		cin >> x >> y;
		for (int i = x; i < x + 10; i++)
		{
			for (int j = y; j < y + 10; j++)
			{
				b[i][j] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (b[i][j] == 1)
			{
				if (b[i + 1][j] == 0) ans++;
				if (b[i - 1][j] == 0) ans++;
				if (b[i][j + 1] == 0) ans++;
				if (b[i][j - 1] == 0) ans++;
			}
		}
	}
	cout << ans;


	return 0;
}