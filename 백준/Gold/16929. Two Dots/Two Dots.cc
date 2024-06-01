#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

char b[55][55];
bool v[55][55];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int n, m;
bool isFind;


void dfs(int x, int y, char color, int sx, int sy, int explored)
{
	v[y][x] = true;
	explored++;
	for (int i = 0; i < 4; i++)
	{
		if (isFind) return;
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
		if (b[ty][tx] != color ) continue;
		if (v[ty][tx])
		{
			if (explored >= 4 && tx == sx && ty == sy)
			{
				isFind = true;
				return;
			}
			continue;
		}
		dfs(tx, ty, color, sx, sy, explored);
	}
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
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				fill(v[k], v[k] + m, false);
			}
			dfs(j, i, b[i][j], j, i, 0);
		}
	}

	if (isFind)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}