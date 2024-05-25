#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int n;
int b[55][55];
int d[55][55];
bool v[55][55];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void bfs01()
{
	deque<pii> dq;
	dq.push_front({ 0, 0 });
	d[0][0] = 0;
	v[0][0] = true;
	while (!dq.empty())
	{
		auto [x, y] = dq.front();
		dq.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
			//if (v[tx][ty]) continue;
			int cost = 1 - b[ty][tx];
			if (d[ty][tx] > d[y][x] + cost)
			{
				d[ty][tx] = d[y][x] + cost;
				if (cost)
					dq.push_back({ tx,ty });
				else
					dq.push_front({ tx,ty });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			b[i][j] = c - '0';
			d[i][j] = 0x3f3f3f3f;
		}
	}

	bfs01();

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		if (d[i][j] == 0x3f3f3f3f)
	//			cout << 'X';
	//		else
	//			cout << d[i][j];
	//	}
	//	cout << '\n';
	//}

	cout << d[n - 1][n - 1];


	return 0;
}