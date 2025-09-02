#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

char b[15][15];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

vector<pii> quest;
int n, m, x, y;
int sx, sy, stdir;
int ex, ey;
int ans;

int getStartDir(int k)
{
	if (k <= m)
	{
		return 3;
	}
	else if (k <= m + n)
	{
		return 2;
	}
	else if (k <= m + n + n)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

pii calcLoc(int k)
{
	if (k <= m)
	{
		return { k, 0 };
	}
	else if (k <= m + n)
	{
		return { 0, k - m };
	}
	else if (k <= m + n + n)
	{
		return { m + 1, k - m - n };
	}
	else
	{
		return { k - n - n - m, n + 1 };
	}
}

bool simulate(int sx, int sy)
{
	int x = sx;
	int y = sy;
	int dir = stdir;
	while (true)
	{
		int tx = x + dx[dir];
		int ty = y + dy[dir];
		if (tx == 0 || ty == 0 || tx == m + 1 || ty == n + 1)
		{
			return tx == ex && ty == ey;
		}
		x = tx;
		y = ty;
		if (b[ty][tx] == '\\')
		{
			if (dir == 0) dir = 1;
			else if (dir == 1) dir = 0;
			else if (dir == 2)dir = 3;
			else dir = 2;
		}
		else if (b[ty][tx] == '/')
		{
			if (dir == 0) dir = 3;
			else if (dir == 1) dir = 2;
			else if (dir == 2)dir = 1;
			else dir = 0;
		}
		else if (b[ty][tx] == '?')
		{
			return false;
		}
	}
}

void func(int k)
{
	if (k >= quest.size())
	{
		ans += simulate(sx, sy);
		ans %= 10007;
		return;
	}
	auto [x, y] = quest[k];
	b[y][x] = '\\';
	func(k + 1);
	b[y][x] = '/';
	func(k + 1);
	b[y][x] = '.';
	func(k + 1);
	b[y][x] = '?';
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> x >> y;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == '?')
			{
				quest.push_back({ j,i });
			}
		}
	}

	stdir = getStartDir(x);
	tie(sx, sy) = calcLoc(x);
	tie(ex, ey) = calcLoc(y);

	func(0);

	cout << ans % 10007;

	return 0;
}