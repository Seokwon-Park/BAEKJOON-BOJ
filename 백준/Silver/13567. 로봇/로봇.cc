#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	int x = 0;
	int y = 0;
	int dir = 2;
	for (int i = 0; i < n; i++)
	{
		string s;
		int j;
		cin >> s >> j;
		if (s == "MOVE")
		{
			int tx = x+  dx[dir] * j;
			int ty = y + dy[dir] * j;
			if (tx < 0 || ty < 0 || tx > m || ty>m)
			{
				cout << -1;
				return 0;
			}
			x = tx;
			y = ty;
		}
		else
		{
			if (j == 0)
				dir = (dir + 1) % 4;
			else
				dir = (dir + 3) % 4;
		}
	}
	cout << x << ' ' << y;

	return 0;
}
