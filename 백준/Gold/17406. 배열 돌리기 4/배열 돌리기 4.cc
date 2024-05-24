#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int n, m, k;
int a[55][55];
int aorigin[55][55];

void resetA()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			a[i][j] = aorigin[i][j];
		}
	}
}

void rotate(int r, int c, int s)
{
	if (s == 0) return;
	int minx = c - s;
	int miny = r - s;
	int maxx = c + s;
	int maxy = r + s;
	int tmp = a[miny][minx];
	for (int y = miny; y < maxy; y++)
	{
		a[y][minx] = a[y + 1][minx];
	}
	for (int x = minx; x < maxx; x++)
	{
		a[maxy][x] = a[maxy][x+1];
	}
	for (int y = maxy; y > miny; y--)
	{
		a[y][maxx] = a[y - 1][maxx];
	}
	for (int x = maxx; x > minx+1; x--)
	{
		a[miny][x] = a[miny][x - 1];
	}
	a[miny][minx + 1] = tmp;
	rotate(r, c, s - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> aorigin[i][j];
		}
	}

	vector<tuple<int, int, int>> rcs;
	vector<int> permu(k);
	for (int i = 0; i < k; i++)
	{
		int r, c, s;
		cin >> r >> c >> s;
		rcs.push_back(tie(r, c, s));
		permu[i] = i;
	}

	int ans = INT_MAX;
	do
	{
		resetA();
		for (int i = 0; i < k; i++)
		{
			int r, c, s;
			tie(r, c, s) = rcs[permu[i]];
			rotate(r, c, s);
		}
		
		int res = INT_MAX;
		for (int i = 1; i <= n; i++)
		{
			int tmp= 0;
			for (int j = 1; j <= m; j++)
			{
				tmp += a[i][j];
			}
			res = min(tmp, res);
		}
		ans = min(res, ans);
	} while (next_permutation(permu.begin(),permu.end()));

	cout << ans;

	return 0;
}