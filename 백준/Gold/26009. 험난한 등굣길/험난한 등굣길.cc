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

int n, m, k;
int b[3005][3005];
int v[3005][3005];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int bfs()
{
	queue<pii> q;
	q.push({ 1,1 });
	int d = 0;
	v[1][1] = 1;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [r, c] = q.front();
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int nr = r + dy[j];
				int nc = c + dx[j];
				if (nr < 1 || nc < 1 || nr > n || nc > m || v[nr][nc] || b[nr][nc]) continue;
				if (nr == n && nc == m)
				{
					return d + 1;
				}
				v[nr][nc] = 1;
				q.push({ nr, nc });
			}
		}
		d++;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		int r, c, d;
		cin >> r >> c >> d;
		int minr = max(r - d, 1);
		int maxr = min(r + d, n);
		for (int y = minr; y <= maxr; y++)
		{
			int gap = d - abs(r - y);
			int st = c - gap;
			int en = c + gap;
			if (st > 0)
			{
				b[y][st] = 1;
			}
			if (en <= m)
			{
				b[y][en] = 1;
			}
		}

	}

	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= m; j++)
	//	{
	//		cout << b[i][j];
	//	}
	//	cout << '\n';
	//}

	int ans = bfs();
	if (ans == -1)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES\n";
		cout << ans;
	}


	return 0;
}