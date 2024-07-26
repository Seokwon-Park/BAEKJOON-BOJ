#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int r, c;
char b[10005][505];
bool v[10005][505];
int dx[3] = { 1,1,1 };
int dy[3] = { -1,0,1 };

bool dfs(int x, int y)
{
	v[y][x] = true;
	if (x == c - 1)
	{
		return v[y][x] = true;
	}
	bool connected = false;
	for (int i = 0; i < 3; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= c || ty >= r) continue;
		if (v[ty][tx] || b[ty][tx] == 'x') continue;
		connected |= dfs(tx, ty);
		if (connected) break;
	}
	return connected;
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
		}
	}

	int ans = 0;
	for (int i = 0; i < r; i++)
	{
		if (dfs(0, i))
			ans++;
	}
	cout << ans;

	return 0;
}