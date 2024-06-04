#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int n, m;
int b[105][105];
int air[105][105];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool v[105][105];

void find_bound()
{
	queue<pii>q;
	q.push({ 0,0 });
	v[0][0] = true;
	while (!q.empty())
	{
		auto [cx, cy] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
			if (v[ty][tx])continue;
			if (b[ty][tx] >= 1)
			{
				b[ty][tx]++;
				continue;
			}
			q.push({ tx,ty });
			v[ty][tx] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int cheese = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
			if (b[i][j])
				cheese++;
		}
	}

	int time = 0;
	while (cheese > 0)
	{
		for (int i = 0; i < n; i++)
			fill(v[i], v[i] + m, false);
		find_bound();

		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cout << b[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (b[i][j] >= 3)
				{
					b[i][j] = 0;
					cheese--;
				}
				else if (b[i][j] == 2)
				{
					b[i][j] = 1;
				}
			}
		}
		time++;
	}

	cout << time;
	

	return 0;
}