#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int b[205][205];
int n, k;
queue<pii> q[1001];

void bfs(int t)
{
	int ct = 0;
	while (ct != t)
	{
		for (int j = 1; j <= k; j++) // 낮은 바이러스 부터 증식.
		{
			if (q[j].empty()) continue;
			int qs = q[j].size();
			for(int s = 0; s <qs; s++)
			{
				auto [x, y] = q[j].front(); q[j].pop();
				for (int i = 0; i < 4; i++)
				{
					int tx = x + dx[i];
					int ty = y + dy[i];
					if (tx < 0 || ty < 0 || tx >= n || ty >= n) continue;
					if (b[ty][tx] != 0) continue;
					b[ty][tx] = j;
					q[j].push({ tx,ty });
				}
			}
		}

		ct++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
			if (b[i][j] != 0)
			{
				q[b[i][j]].push({ j, i });
			}
		}
	}

	int s, x, y;
	cin >> s >> x >> y; 

	bfs(s);


	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << b[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	cout << b[x - 1][y - 1];

	return 0;
}