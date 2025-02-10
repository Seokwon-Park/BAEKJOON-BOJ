#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int b[1005][1005];
int v[1005][1005];
int dy[6] = { 0,-1,-1,0,1,1 };
int dx1[6] = { -1,-1,0,1,0,-1 };
int dx2[6] = { -1,0,1,1,1,0 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;
		b[r][c] = 1;
	}

	queue<pii> q;
	q.push({ 0,0 });
	v[0][0] = true;
	int d = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [x, y] = q.front();
			q.pop();
			if (x == m - 1 && y == n - 1)
			{
				cout << d;
				return 0;
			}
			for (int j = 0; j < 6; j++)
			{
				int tx = 0;
				if (y % 2 == 0)
				{
					tx = x + dx1[j];
				}
				else
				{
					tx = x + dx2[j];
				}
				int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
				if (b[ty][tx] == 1) continue;
				q.push({ tx,ty });
				b[ty][tx] = 1;
			}
		}
		d++;
	}
	cout << -1;

	return 0;
}



