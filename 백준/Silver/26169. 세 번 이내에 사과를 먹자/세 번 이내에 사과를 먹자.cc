#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int b[5][5];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1};
bool ans = false;

void dfs(int r, int c, int moved, int eat)
{
	if (moved == 3)
	{
		//cout << eat << '\n';
		ans |= (eat >= 2);
		return;
	}
	int saved = b[r][c];
	for (int i = 0; i < 4; i++)
	{
		int tx = c + dx[i];
		int ty = r + dy[i];
		if (tx < 0 || ty < 0 || tx >= 5 || ty >= 5)continue;
		if (b[ty][tx] == -1) continue;
		if (b[ty][tx] == 1)
		{
			b[r][c] = -1;
			dfs(ty, tx, moved + 1, eat + 1);
			if (ans) return;
			b[r][c] = saved;
		}
		else
		{
			b[r][c] = -1;
			dfs(ty, tx, moved + 1, eat);
			if (ans) return;
			b[r][c] = saved;
		}
	}
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
		}
	}
	int r, c;
	cin >> r >> c;
	dfs(r, c, 0, 0);
	cout << ans;

	return 0;
}