#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int dice[7];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		fill(dice + 1, dice + 7, 0);
		for (int j = 0; j < 4; j++)
		{
			int m;
			cin >> m;
			dice[m]++;
		}
		int tmp = 0;
		auto resix = max_element(dice + 1, dice + 7);
		int res = *resix;
		if (res == 4)
		{
			tmp = 50000 + (resix - dice) * 5000;
		}
		else if (res == 3)
		{
			tmp = 10000 + (resix - dice) * 1000;
		}
		else if (res == 2)
		{
			if (count(dice + 1, dice + 7, 2) > 1)
			{
				tmp = 2000;
				for(int i = 1; i<=6; i++)
				{
					if (dice[i] == 2)
					{
						tmp += i * 500;
					}
				}
			}
			else
			{
				tmp = 1000 + (resix - dice) * 100;
			}
		}
		else
		{
			for (int i = 6; i >= 1; i--)
			{
				if (dice[i])
				{
					tmp = 100 * i;
					break;
				}
			}
		}

		ans = max(tmp, ans);
	}
	cout << ans;

	return 0;
}