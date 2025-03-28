#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[5]= { 0, -1,0,1,0 };
int dy[5] = { 0, 0,-1,0,1 };
int r, c, t;
char b[105][105];
int ans;

void dfs(int x, int y, int cur, int eat)
{
	bool isEat = false;
	if (b[y][x] == 'S')
	{
		eat++;
		b[y][x] = '.';
		isEat = true;
	}
	if (cur == t)
	{
		ans = max(ans, eat);
		if (isEat)
		{
			b[y][x] = 'S';
		}
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= c || ty >= r) continue;
		if (b[ty][tx] == '#') continue;
		dfs(tx, ty, cur + 1, eat);
	}
	if (isEat)
	{
		b[y][x] = 'S';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c >> t;

	int x, y;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 'G')
			{
				x = j;
				y = i;
			}
		}
	}

	dfs(x, y, 0, 0);

	cout << ans;


	
	return 0;
} 