#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

char b[11][11];
bool v[11][11];
int after[11][11];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int bfs(int sx, int sy)
{
	queue<pii> q;
	q.push({ sx,sy });
	v[sy][sx] = true;
	int moved = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [x, y] = q.front();
			q.pop();
			if (after[y][x] == 0)
			{
				return moved;
			}
			for (int j = 0; j < 4; j++)
			{
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 1 || ty < 1 || tx >10 || ty>10) continue;
				if (v[ty][tx]) continue;
				v[ty][tx] = true;
				q.push({ tx,ty });
			}
		}
		moved++;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int r, c;
	cin >> r >> c;
	

	
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (b[i][j] == 'o')
			{
				for (int k = 1; k <= 10; k++)
				{
					after[i][k] = 1;
					after[k][j] = 1;
				}
			}
		}
	}

	cout << bfs(c, r);

	return 0;
}

