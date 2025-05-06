#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int n, m;
char b[35][35];
bool v[35][35];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int total;
int ans = INF;

void check(int x, int y, int cur, int dir, int moved)
{
	v[y][x] = true;
	cur += 1;
	if (moved > ans)
	{
		cur -= 1;
		v[y][x] = false;
		return;
	}
	if (cur == total)
	{
		ans = min(ans, moved);
		cur -= 1;
		v[y][x] = false;
		return;
	}
	int tx = x + dx[dir];
	int ty = y + dy[dir];
	if (tx < 0 || ty < 0 || tx >= m || ty >= n || b[ty][tx] == '*' || v[ty][tx] == true)
	{
		for (int i = 0; i < 4; i++)
		{
			tx = x + dx[i];
			ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= m || ty >= n || b[ty][tx] == '*' || v[ty][tx] == true) continue;
			check(tx, ty, cur, i, moved+1);
		}
	}
	else
	{
		check(tx, ty, cur, dir, moved);
	}
	cur -= 1;
	v[y][x] = false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc = 1;
	while (cin >> n >> m)
	{
		ans = INF;
		total = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> b[i][j];
				total += b[i][j] == '.';
			}
		}

		if (total != 1)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (b[i][j] == '.')
					{
						for (int dir = 0; dir < 4; dir++)
						{
							int tx = j + dx[dir];
							int ty = i + dy[dir];
							if (tx < 0 || ty < 0 || tx >= m || ty >= n || b[ty][tx] == '*' || v[ty][tx] == true)continue;
							check(j, i, 0, dir, 1);
						}
					}
				}
			}
		}
		else
		{
			ans = 0;
		}
		cout << "Case " << tc++ << ": ";
		if (ans == INF)
		{
			cout << "-1\n";
		}
		else
		{
			cout << ans << '\n';
		}
	}


	return 0;
}