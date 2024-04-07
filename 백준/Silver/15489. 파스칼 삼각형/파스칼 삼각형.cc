#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<vector<int>> tri(31, vector<int>(31));
	tri[0][0] = 1;
	for (int y = 1; y < 30; y++)
	{
		for (int x = 0; x <= y; x++)
		{
			if (x == 0 || x == y)
			{
				tri[y][x] = 1;
			}
			else
			{
				tri[y][x] = tri[y - 1][x - 1] + tri[y - 1][x];
			}
		}
	}
	int r, c, w;
	cin >> r >> c >> w;
	// 1-indexed => 0-indexed;
	r--;
	c--;
	int ans = 0;
	for (int i = r; i < r+w; i++)
	{
		for (int j = c; j < c + (i - r) + 1; j++)
		{
			ans += tri[i][j];
		}
	}

	cout << ans;

	return 0;
}