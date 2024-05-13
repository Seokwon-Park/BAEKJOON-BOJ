#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int dice[10000][6];

int opposite(int m)
{
	switch (m)
	{
	case 0:return 5; break;
	case 1:return 3; break;
	case 2:return 4; break;
	case 3:return 1; break;
	case 4:return 2; break;
	case 5:return 0; break;
	}
}

int getMax(int ix, int up)
{
	if (up == 0 || up == 5)
	{
		return max({dice[ix][1], dice[ix][2], dice[ix][3], dice[ix][4]});
	}
	else if (up == 1 || up == 3)
	{
		return max({ dice[ix][0], dice[ix][2], dice[ix][4], dice[ix][5] });
	}
	else
	{
		return max({ dice[ix][0], dice[ix][1], dice[ix][3], dice[ix][5] });
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
		
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> dice[i][j];
		}
	}

	int up = 0;
	int ans = 0;
	for (int i = 0; i < 6; i++)
	{
		up = dice[0][i];
		int res = getMax(0, i);
		for (int j = 1; j < n; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				if (dice[j][k] == up)
				{
					int upix = opposite(k);
					up = dice[j][upix];
					res += getMax(j, upix);
					break;
				}
			}
		}
		ans = max(ans, res);
	}
	cout << ans;

	return 0;
}