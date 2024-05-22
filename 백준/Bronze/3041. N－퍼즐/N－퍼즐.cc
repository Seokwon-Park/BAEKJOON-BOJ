#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

char b[4][4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 16; i++)
	{
		cin >> b[i / 4][i % 4];
	}

	int ans = 0;
	for (int i = 0; i < 16; i++)
	{
		if (b[i / 4][i % 4] != 'A' + i)
		{
			int ix = 0;
			for (int j = 0; j < 16; j++)
			{
				if (b[j / 4][j % 4] == 'A' + i)
				{
					ix = j;
					ans += abs(i / 4 - j / 4) + abs(i % 4 - j % 4);
					//swap(b[i / 4][i % 4], b[j / 4][j % 4]);
					break;
				}
			}
		}
	}

	cout << ans;

	return 0;
}