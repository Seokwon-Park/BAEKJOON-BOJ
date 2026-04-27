#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int w, h, n, d, b;
int f[105][105];
int v[105][105];
int sx, sy;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int bfs()
{
	int res = 0;
	queue<pii> q;
	q.push({ sx,sy });
	v[sy][sx] = 1;
	res++;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j <= d; j++)
			{
				int tx = x + dx[i] * j;
				int ty = y + dy[i] * j;
				if (tx <1 || ty < 1 || tx>w || ty > h || v[ty][tx] || !f[ty][tx]) continue;
				res++;
				q.push({ tx,ty });
				v[ty][tx] = 1;
			}
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> w >> h >> n >> d >> b)
	{
		if (w + h + n + d + b == 0) break;
		
		for (int i = 1; i <= h; i++)
		{
			fill(f[i], f[i] + w + 1, 0);
			fill(v[i], v[i] + w + 1, 0);
		}

		for (int i = 1; i <= n; i++)
		{
			int x, y;
			cin >> x >> y;
			f[y][x] = 1;
			if (i == b)
			{
				sx = x;
				sy = y;
			}
		}
		cout << bfs() << '\n';
	}

	return 0;
}