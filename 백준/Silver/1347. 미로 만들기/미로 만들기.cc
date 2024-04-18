#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

vector<pair<int, int>> route;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cx = 0;
	int cy = 0;
	int dir = 3;
	int n;
	string s;
	cin >> n >> s;
	int minx = 0;
	int maxx = 0;
	int miny = 0;
	int maxy = 0;

	route.push_back({ 0, 0 });

	for (auto c : s)
	{
		if (c == 'R')
			dir = (dir + 1) % 4;
		if (c == 'L')
			dir = (dir + 3) % 4;
		if (c == 'F')
		{
			cx += dx[dir];
			cy += dy[dir];
			route.push_back({ cx, cy });
			minx = min(minx, cx);
			miny = min(miny, cy);
			maxx = max(maxx, cx);
			maxy = max(maxy, cy);
		}
	}

	int xgap = abs(minx);
	int ygap = abs(miny);
	minx = 0;
	miny = 0;
	maxx += xgap;
	maxy += ygap;

	vector<vector<char>> v(maxy+1, vector<char>(maxx+1, '#'));

	for (auto [x, y] : route)
	{
		v[y + ygap][x + xgap] = '.';
	}

	for (int i = 0; i <= maxy; i++)
	{
		for (int j = 0; j <= maxx; j++)
		{
			cout << v[i][j];
		}
		cout << '\n';
	}

	return 0;
}