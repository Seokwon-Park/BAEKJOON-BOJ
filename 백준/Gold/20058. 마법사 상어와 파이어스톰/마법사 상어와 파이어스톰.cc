#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int n;
int b[70][70];
int v[70][70];
int melt[70][70];
int copyMat[70][70];
int rotated[70][70];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void rotate(int x, int y, int sz)
{
	if (sz == 1)return;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			copyMat[i][j] = b[y + i][x + j];
		}
	}

	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			rotated[j][sz - i - 1] = copyMat[i][j];
		}
	}

	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			b[y + i][x + j] = rotated[i][j];
		}
	}
}

void magic(int m)
{
	for (int i = 0; i < n; i++)
	{
		fill(melt[i], melt[i] + n, 0);
	}
	for (int i = 0; i < n; i += m)
	{
		for (int j = 0; j < n; j += m)
		{
			rotate(j, i, m);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i][j] == 0) continue;
			int connect = 0;
			for (int k = 0; k < 4; k++)
			{
				int tx = j + dx[k];
				int ty = i + dy[k];
				if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
				if (b[ty][tx] == 0) continue;
				connect++;
			}
			if (connect < 3)
			{
				melt[i][j]++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] -= melt[i][j];
		}
	}
}

int bfs(pii xy)
{
	queue<pii> q;
	q.push(xy);
	v[xy.second][xy.first] = 1;
	int explored = 0;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		explored++;
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= n) continue;
			if (v[ty][tx] || b[ty][tx] == 0)continue;
			q.push({ tx,ty });
			v[ty][tx] = true;
		}
	}
	return explored;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int nn, q;
	cin >> nn >> q;
	n = 1 << nn;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < q; i++)
	{
		int l;
		cin >> l;
		magic(1 << l);
	}

	//for (int k = 0; k < n; k++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << b[k][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	int ans = 0;
	int area = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans += b[i][j];
			if (!v[i][j] && b[i][j] != 0)
			{
				area = max(area, bfs({j, i}));
			}
		}
	}
	cout << ans << '\n';
	cout << area;

	return 0;
}
