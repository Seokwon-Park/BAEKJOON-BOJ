#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[500][500];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	vector<int> v(w);

	for (int i = 0; i < w; i++)
	{
		int hh;
		cin >> hh;
		for (int j = h-hh; j < h; j++)
		{
			b[j][i] = 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (b[i][j] == 0)
			{
				bool lBlocked = false;
				bool rBlocked = false;
				int l = 1;
				int r = 1;
				while (j - l >= 0)
				{
					if (b[i][j - l] == 1)
					{
						lBlocked = true;
						break;
					}
					l++;
				}
				while (j + r < w)
				{
					if (b[i][j + r] == 1)
					{
						rBlocked = true;
						break;
					}
					r++;
				}
				if (lBlocked && rBlocked)
				{
					ans++;
				}
			}
		}
	}

	cout << ans;

	return 0;
}