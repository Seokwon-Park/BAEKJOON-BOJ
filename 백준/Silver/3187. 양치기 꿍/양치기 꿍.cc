#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

char b[255][255];
bool v[255][255];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int r, c;
int sh, wf;

void bfs(int x, int y)
{
	queue<pii> q;
	q.push({ x,y });
	v[y][x] = true;
	int sheep = 0;
	int wolf = 0;
	while (!q.empty())
	{
		auto [cx, cy] = q.front();
		q.pop();
		if (b[cy][cx] == 'v')
			wolf++;
		else if (b[cy][cx] == 'k')
			sheep++;
		for (int i = 0; i < 4; i++)
		{
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (tx < 0 || ty < 0 || tx >= c || ty >= r)continue;
			if (v[ty][tx] || b[ty][tx] == '#')continue;
			q.push({ tx,ty });
			v[ty][tx] = true;
		}
	}
	if (wolf < sheep)
	{
		sh += sheep;
	}
	else
	{
		wf += wolf;
	}
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
		}
	}


	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (b[i][j] != '#' && !v[i][j])
			{
				bfs(j, i);
			}
		}
	}

	cout << sh << ' ' << wf;

	return 0;
}