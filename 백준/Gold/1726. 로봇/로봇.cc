#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int m, n;
int ex, ey, edir;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
const int MX = 100 + 5;
int b[MX][MX];
bool v[MX][MX][4];
int d[MX][MX];

int rotateLeft(int dir)
{
	if (dir == 0) return 3;
	if (dir == 1) return 2;
	if (dir == 2) return 0;
	if (dir == 3)return 1;
}

int rotateRight(int dir)
{
	if (dir == 0) return 2;
	if (dir == 1) return 3;
	if (dir == 2) return 1;
	if (dir == 3)return 0;
}

void bfs(int x, int y, int dir)
{
	queue<tiii> q;
	q.push(tie(x, y, dir));
	v[y][x][dir] = 1;
	int dist = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int k = 0; k < qs; k++)
		{
			int cx, cy, cdir;
			tie(cx, cy, cdir) = q.front();
			q.pop();
			if (cx == ex && cy == ey && cdir == edir)
			{
				cout << dist;
				return;
			}
			int ldir = rotateLeft(cdir);
			int rdir = rotateRight(cdir);
			if (!v[cy][cx][ldir])
			{
				q.push({ cx, cy, ldir });
				v[cy][cx][ldir] = true;
			}
			if (!v[cy][cx][rdir])
			{
				q.push({ cx, cy, rdir});
				v[cy][cx][rdir] = true;

			}
			for (int i = 1; i <= 3; i++)
			{
				int tx = cx + dx[cdir] * i;
				int ty = cy + dy[cdir] * i;
				if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
				if (b[ty][tx]) break;
				if (v[ty][tx][cdir]) continue;
				q.push({ tx,ty,cdir });
				v[ty][tx][cdir] = true;

			}
		}
		dist++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	int sx, sy, sdir;
	cin >> sy >> sx >> sdir;
	sx--;
	sy--;
	sdir--;
	cin >> ey >> ex >> edir;
	ex--;
	ey--;
	edir--;
	bfs(sx, sy, sdir);

	//cout << d[ey][ex]


	return 0;
}