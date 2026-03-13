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

int sx, sy;
int ex, ey;
int n, m;
int k, c;
int b[105][105];
int v[105][105][105];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int bfs()
{
	queue<tiii> q;
	q.push({ sx, sy, 0 });
	v[sy][sx][0] = 1;
	int d = 0;
	while (!q.empty())
	{
		int qs = q.size();
		d++;
		for (int i = 0; i < qs; i++)
		{
			auto [cx, cy, cb] = q.front();
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int tx = cx + dx[j];
				int ty = cy + dy[j];
				if (tx < 0 || ty < 0 || tx >= m || ty >= n || b[ty][tx] == 1)continue;
				int tb = b[ty][tx] == 2 ? max(0, cb - k) : min(100, cb + c);
				if (tb == 100) continue;
				if (ty == ey && tx == ex) return d;
				if (v[ty][tx][tb]) continue;
				v[ty][tx][tb] = 1;
				q.push({ tx,ty,tb });
			}
			if (b[cy][cx] == 2)
			{
				int tb = max(0, cb - k);
				if (!v[cy][cx][tb])
				{
					v[cy][cx][tb] = 1;
					q.push({ cx,cy,tb });
				}
			}
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	cin >> k >> c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char ch;
			cin >> ch;
			switch (ch)
			{
			case '.':
				b[i][j] = 0;
				break;
			case 'S':
				sx = j;
				sy = i;
				break;
			case 'H':
				b[i][j] = 2;
				break;
			case '#':
				b[i][j] = 1;
				break;
			case 'E':
				ex = j;
				ey = i;
				break;
			}
		}
	}

	cout << bfs();



	return 0;
}