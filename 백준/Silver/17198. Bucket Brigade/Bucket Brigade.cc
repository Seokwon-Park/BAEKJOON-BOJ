#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
char b[10][10];
char v[10][10];

int bfs(int xx, int yy)
{
	queue<pii> q;
	q.push({ xx,yy });
	v[yy][xx] = true;
	int dist = 0;
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
				if (tx < 0 || ty < 0 || tx >= 10 || ty >= 10) continue;
				if (v[ty][tx] || b[ty][tx] == 'R')continue;
				if (b[ty][tx] == 'L')return dist;
				q.push({ tx,ty });
				v[ty][tx] = true;
			}
		}
		dist++;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (b[i][j] == 'B')
			{
				cout << bfs(j, i);
				return 0;
			}
		}
	}

	return 0;
}