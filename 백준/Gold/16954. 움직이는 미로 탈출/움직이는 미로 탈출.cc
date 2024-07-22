#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

char b[8][8];
bool v[8][8];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

void pushWall()
{
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			if (b[i][j] == '#')
			{
				b[i][j] = '.';
			}
			if (b[i-1][j] == '#')
			{
				b[i][j] = b[i-1][j];
				b[i - 1][j] = '.';
			}
		}
	}
}

bool bfs()
{
	queue<pii> q;
	q.push({ 0, 7 });
	v[7][0] = 1;
	while (!q.empty())
	{
		int qs = q.size();
		for (int j = 0; j < qs; j++)
		{
			auto [x, y] = q.front();
			q.pop();
			if (y - 1 >= 0 && b[y - 1][x] != '#')
			{
				q.push({ x,y });
			}
			for (int i = 0; i < 8; i++)
			{
				int tx = x + dx[i];
				int ty = y + dy[i];
				if (tx < 0 || ty < 0 || tx >= 8 || ty >= 8) continue;
				if (b[ty][tx] == '#' || v[ty][tx]) continue;
				if (ty - 1 >= 0 && b[ty - 1][tx] == '#') continue;
				if (tx == 7 && ty == 0)
				{
					return true;
				}
				q.push({ tx,ty });
				v[ty][tx] = 1;
			}
		}
		pushWall();
		//for (int i = 0; i < 8; i++)
		//{
		//	for (int j = 0; j < 8; j++)
		//	{
		//		cout << b[i][j];
		//	}
		//	cout << '\n';
		//}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> b[i][j];
		}
	}

	cout << bfs();

	return 0;
}