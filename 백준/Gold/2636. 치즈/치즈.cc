#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int r, c;
int b[105][105];
bool v[105][105];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int cheese;

pii bfs()
{
	queue<pii> q;
	queue<pii> melt;
	q.push({ 0,0 });
	v[0][0] = true;
	int time = 0;
	while (cheese > 0)
	{
		while (!q.empty())
		{
			auto [x, y] = q.front();
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx >= c || ty >= r) continue;
				if (v[ty][tx]) continue;
				if (b[ty][tx] == 1)
				{
					melt.push({ tx,ty });
				}
				else
				{
					q.push({ tx,ty });
				}
				v[ty][tx] = true;
			}
		}
		int leftcheese = cheese;
		int qs = melt.size();
		for (int i = 0; i < qs; i++)
		{
			auto [x, y] = melt.front();
			cheese--;
			b[y][x] = 0;
			melt.pop();
			for (int j = 0; j < 4; j++)
			{
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx >= c || ty >= r) continue;
				if (v[ty][tx]) continue;
				if (b[ty][tx] == 1)
				{
					melt.push({ tx,ty });
				}
				else
				{
					q.push({ tx,ty });
				}
				v[ty][tx] = true;
			}
		}
		time++;
		if (cheese == 0)
		{
			return { time , leftcheese };
		}
	}
	return { 0, 0 };
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
			if (b[i][j] == 1)
			{
				cheese++;
			}
		}
	}

	auto [a,b] = bfs();
	cout << a << '\n' << b;

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