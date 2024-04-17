#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[1005][1005];
bool v[1005][1005];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int n, m;

bool isPercolate(int x, int y)
{
	queue<pair<int, int>>q;
	q.push({ x,y });
	while (!q.empty())
	{
		auto [cx, cy] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
			if (v[ty][tx]||b[ty][tx] == 1) continue;
			if (ty == n - 1)
			{
				return true;
			}
			v[ty][tx] = true;
			q.push({ tx,ty });

		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			b[i][j] = c - '0';
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (b[0][i] == 0 && !v[0][i])
			if (isPercolate(i, 0))
			{
				cout << "YES";
				return 0;
			}
	}

	cout << "NO";

	return 0;
}