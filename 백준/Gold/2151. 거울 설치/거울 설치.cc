#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int n;
char b[55][55];
int v[55][55][4];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool findStart = false;
int sx, sy;
int ex, ey;

void bfs(int xx, int yy)
{
	queue<vector<int>> q;
	for (int i = 0; i < 4; i++)
	{
		q.push({ xx, yy, i });
		v[yy][xx][i] = 0;
	}
	while (!q.empty())
	{
		int x = q.front()[0];
		int y = q.front()[1];
		int dir = q.front()[2];
		q.pop();
		int tx = x + dx[dir];
		int ty = y + dy[dir];
		if (tx < 0 || ty < 0 || tx >= n || ty >= n || b[ty][tx] == '*')continue;
		if (b[ty][tx] == '!')
		{
			if (v[ty][tx][dir] > v[y][x][dir])
			{
				v[ty][tx][dir] = v[y][x][dir];
				q.push({ tx,ty,dir });
			}
			if (v[ty][tx][(dir + 1) % 4] > v[y][x][dir] + 1)
			{
				v[ty][tx][(dir + 1) % 4] = v[y][x][dir] + 1;
				q.push({ tx,ty,(dir + 1) % 4 });
			}
			if (v[ty][tx][(dir + 3) % 4] > v[y][x][dir] + 1)
			{
				v[ty][tx][(dir + 3) % 4] = v[y][x][dir] + 1;
				q.push({ tx,ty,(dir + 3) % 4 });
			}
		}
		else if (b[ty][tx] == '.')
		{
			q.push({ tx,ty, dir });
			v[ty][tx][dir] = v[y][x][dir];
		}
		else if (b[ty][tx] == '#')
		{
			v[ty][tx][dir] = v[y][x][dir];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fill(v[i][j], v[i][j] + 4, INF);
			cin >> b[i][j];
			if (b[i][j] == '#')
			{
				if (!findStart)
				{
					sx = j;
					sy = i;
					findStart = true;
				}
				else
				{
					ex = j;
					ey = i;
				}
			}
		}
	}

	bfs(sx, sy);

	cout << *min_element(v[ey][ex], v[ey][ex] + 4);

	return 0;
}