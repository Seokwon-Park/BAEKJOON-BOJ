#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int b[5][5];
int x, y;

int v[5][5][7];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

bool iswall(int x, int y)
{
	if (x < 0 || y < 0 || x >= 5 || y >= 5 || b[y][x] == -1)
	{
		return true;
	}
	return false;

}
pii rush(int x, int y, int dir)
{
	int tx;
	int ty;
	while (1)
	{
		tx = x + dx[dir];
		ty = y + dy[dir];

		if (iswall(tx, ty))break;

		x = tx;
		y = ty;
		if (b[y][x] == 7)break;

	}
	return { x,y };
}

int bfs()
{
	queue<tiii> q;
	q.push({ x,y,0 });
	v[y][x][0] = true;
	int d = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [x, y, nxt] = q.front();
			q.pop();
			if (nxt == 6) return d;
			for (int j = 0; j < 4; j++)
			{
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (iswall(tx, ty)) continue;
				if (v[ty][tx][nxt] <= d + 1)continue;
				v[ty][tx][nxt] = d + 1;

				if (b[ty][tx] == nxt + 1)
				{
					q.push({ tx,ty,nxt + 1 });
				}
				else
				{
					q.push({ tx,ty,nxt });
				}
			}

			for (int j = 0; j < 4; j++)
			{
				auto [tx, ty] = rush(x, y, j);
				if (v[ty][tx][nxt] <= d + 1)continue;
				v[ty][tx][nxt] = d + 1;
				if (b[ty][tx] == nxt + 1)
				{
					q.push({ tx,ty,nxt + 1 });
				}
				else
				{
					q.push({ tx,ty,nxt });
				}
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

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> b[i][j];
			fill(v[i][j], v[i][j] + 7, INF);
		}
	}
	cin >> y >> x;
	cout << bfs();



	return 0;
}