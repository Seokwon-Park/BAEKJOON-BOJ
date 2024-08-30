#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int b[55][55];
int n, m, t;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void RotateC(int xi, int k)
{
	vector<int> tmp(m);
	for (int i = 0; i < m; i++)
		tmp[i] = b[xi][(i - k + m) % m];

	for (int i = 0; i < m; i++)
		b[xi][i] = tmp[i];

}

void RotateCC(int xi, int k)
{
	vector<int> tmp(m);
	for (int i = 0; i < m; i++)
		tmp[i] = b[xi][(i + k) % m];

	for (int i = 0; i < m; i++)
		b[xi][i] = tmp[i];
}

void bfs(int x, int y, int c)
{
	b[y][x] = 0;
	queue<pii> q;
	q.push({ x,y });
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = (x + dx[i] + m) % m;
			int ty = y + dy[i];
			if (ty <1 || ty > n) continue;
			if (b[ty][tx] == c)
			{
				b[ty][tx] = 0;
				q.push({ tx,ty });
				
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < t; i++)
	{
		int x, d, k;
		cin >> x >> d >> k;

		for (int j = x; j <= n; j += x)
		{
			if (d == 0)
				RotateC(j, k);
			else
				RotateCC(j, k);
		}

		bool isNv = false;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (b[i][j] == 0)continue;
				for (int k = 0; k < 4; k++)
				{
					int tx = (j + dx[k] + m) % m;
					int ty = i + dy[k];
					if (ty <1 || ty >n)continue;
					if (b[i][j] == b[ty][tx])
					{
						isNv = true;
						bfs(j, i, b[i][j]);
						break;
					}
				}
			}
		}

		if (!isNv)
		{
			int total = 0;
			int cnt = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (b[i][j] != 0)
					{
						total += b[i][j];
						cnt++;
					}
				}
			}
			
			for (int i = 1; i <= n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (b[i][j] == 0) continue;
					if (b[i][j] * cnt > total)
						b[i][j]--;
					else if(b[i][j] * cnt < total)
						b[i][j]++;
				}
			}
		}
		cout << "";
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans += b[i][j];
		}
	}
	cout << ans;

	return 0;
}
