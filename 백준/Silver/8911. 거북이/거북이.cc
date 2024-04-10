#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int dir = 3;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		string cmd;
		cin >> cmd;
		int xmin= 0;
		int ymin = 0;
		int xmax = 0;
		int ymax = 0;
		int x = 0, y = 0;
		for (char c : cmd)
		{
			if (c == 'F')
			{
				x += dx[dir];
				y += dy[dir];
			}
			else if (c == 'L')
			{
				dir = (dir + 1) % 4;
			}
			else if (c == 'R')
			{
				dir = (dir + 3) % 4;
			}
			else
			{
				x -= dx[dir];
				y -= dy[dir];
			}
			xmin = min(xmin, x);
			ymin = min(ymin, y);
			xmax = max(xmax, x);
			ymax = max(ymax, y);
		}
		cout << (xmax - xmin) * (ymax - ymin) << '\n';
	}


	return 0;
}