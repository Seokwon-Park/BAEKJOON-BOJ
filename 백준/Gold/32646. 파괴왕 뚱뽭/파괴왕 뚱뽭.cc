#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int b[105][105];
int d[105][105][105];

bool tp[105][105];
pii tpmap[105][105];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k, t, q;
	cin >> n >> m >> k >> t >> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		int sx, sy, ex, ey;
		cin >> sy >> sx >> ey >> ex;
		tp[sy][sx] = true;
		tpmap[sy][sx] = { ex,ey };
	}

	for (int i = 0; i <= t; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int l = 1; l <= m; l++)
			{
				d[i][j][l] = INF;
			}
		}
	}

	d[0][1][1] = 0;

	priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
	pq.push({ 0,0,1,1 });

	while (!pq.empty())
	{
		auto [cost, curt, x, y] = pq.top();
		pq.pop();
		if (cost != d[curt][y][x]) continue;
		//일반 이동
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 1 || ty < 1 || tx >m || ty > n) continue;
			if (d[curt][ty][tx] <= d[curt][y][x] + b[ty][tx]) continue;
			d[curt][ty][tx] = d[curt][y][x] + b[ty][tx];
			pq.push({ d[curt][ty][tx], curt, tx, ty });
		}
		//텔포
		if (tp[y][x])
		{
			auto [tx, ty] = tpmap[y][x];
			int nxtt = curt + 1;
			if (d[nxtt][ty][tx] <= d[curt][y][x]) continue;
			d[nxtt][ty][tx] = d[curt][y][x];
			pq.push({ d[nxtt][ty][tx], nxtt, tx,ty });
		}
	}

	for (int i = 0; i < q; i++)
	{
		int p, x, y;
		cin >> p >> y >> x;
		bool poss = false;
		for (int j = 0; j <= t; j++)
		{
			if (d[j][y][x] <= p)
			{
				poss = true;
				break;
			}
		}
		cout << poss << '\n';
	}

	return 0;
}