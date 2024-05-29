
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int n, m;
char b[21][21];
bool v[21][21][21][21];
vector<pii> coin;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int bfs()
{
	auto [x1, y1] = coin[0];
	auto [x2, y2] = coin[1];
	queue<vector<int>> q;
	q.push({ x1,y1,x2,y2 });
	v[x1][y1][x2][y2] = 1;
	int pressed = 0;
	bool isOut1 = false;
	bool isOut2 = false;
	while (!q.empty() && pressed<10)
	{
		int qs = q.size();
		for (int j = 0; j < qs; j++)
		{
			int cx1, cy1, cx2, cy2;
			cx1 = q.front()[0];
			cy1 = q.front()[1];
			cx2 = q.front()[2];
			cy2 = q.front()[3];
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int tx1 = cx1 + dx[i];
				int ty1 = cy1 + dy[i];
				int tx2 = cx2 + dx[i];
				int ty2 = cy2 + dy[i];
				if (tx1 < 0 || tx1 >= m || ty1 < 0 || ty1 >= n)
				{
					isOut1 = true;
				}
				if (tx2 < 0 || tx2 >= m || ty2 < 0 || ty2 >= n)
				{
					isOut2 = true;
				}
				if (isOut1)
				{
					if (isOut2)
					{
						isOut1 = false;
						isOut2 = false;
						continue;
					}
					return pressed + 1;
				}
				if (isOut2)
				{
					if (isOut1)
					{
						isOut1 = false;
						isOut2 = false;
						continue;
					}
					return pressed + 1;
				}
				if (b[ty1][tx1] == '#')
				{
					tx1 = cx1;
					ty1 = cy1;
				}
				if (b[ty2][tx2] == '#')
				{
					tx2 = cx2;
					ty2 = cy2;
				}
				if (v[tx1][ty1][tx2][ty2]) continue;

				v[tx1][ty1][tx2][ty2] = true;
				q.push({ tx1,ty1,tx2,ty2 });
			}
		}
		pressed++;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 'o')
			{
				coin.push_back({ j, i });
			}
		}
	}

	cout << bfs();

	return 0;
}