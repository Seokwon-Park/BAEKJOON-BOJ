#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

char b[55][55];
bool v[55][55];
int water[55][55];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int sx, sy;
int r, c;
queue<pii> q;

void wbfs()
{
	int d = 1;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [x, y] = q.front();
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx >= c || ty >= r) continue;
				if (v[ty][tx] || b[ty][tx] == 'D' || b[ty][tx] == 'X')continue;
				q.push({ tx,ty });
				v[ty][tx] = true;
				water[ty][tx] = d;
			}
		}
		d++;
	}
}

int bfs()
{
	queue<pii> qq;
	qq.push({ sx,sy });
	v[sy][sx] = true;
	int d = 1;
	while (!qq.empty())
	{
		int qs = qq.size();
		for (int i = 0; i < qs; i++)
		{
			auto [x, y] = qq.front();
			qq.pop();
			for (int j = 0; j < 4; j++)
			{
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx >= c || ty >= r) continue;
				if (b[ty][tx] == 'D') return d;
				if (v[ty][tx] || b[ty][tx] == 'X' || d >= water[ty][tx])continue;
				qq.push({ tx,ty });
				v[ty][tx] = true;
			}
		}
		d++;
	}
	return -1;
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == '*')
			{
				q.push({ j,i });
				v[i][j] = true;
			}
			if (b[i][j] == 'S')
			{
				sx = j;
				sy = i;
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		fill(water[i], water[i] + c, 0x3f3f3f);
	}
	wbfs();
	for (int i = 0; i < r; i++)
	{
		fill(v[i], v[i] + c, false);
	}
	int res = bfs();

	if (res == -1)
		cout << "KAKTUS";
	else
		cout << res << '\n';

	//for (int i = 0; i < r; i++)
	//{
	//	for (int j = 0; j < c; j++)
	//	{
	//		cout << water[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}


	return 0;
}