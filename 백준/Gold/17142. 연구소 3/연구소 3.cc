#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int n, m;
int b[55][55];
int v[55][55];
//char g[55][55];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int bfs(queue<pii> q, int blank)
{
	int cur = blank;
	int t = 0;
	if (cur == 0)
		return 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [x, y] = q.front();
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
				if (v[ty][tx] || b[ty][tx] == 1)continue;
				q.push({ tx,ty });
				v[ty][tx] = true;
				if (b[ty][tx] != 2)
					cur--;
				//if (b[ty][tx] == 2)
				//{
				//	g[ty][tx] = '*';
				//}
				//else
				//{
				//	g[ty][tx] = t + 1 + '0';
				//	cur--;
				//}
				if (cur == 0)
					return t+1;
			}
		}
		t++;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<pii> virus;
	int blank = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 0)
			{
				blank++;
			}
			//if (b[i][j] == 1)
			//{
			//	g[i][j] = '-';
			//}
			if (b[i][j] == 2)
			{
				virus.push_back({ j, i });
			}

		}
	}

	vector<int> c(virus.size(), 0);
	fill(c.end() - m, c.end(), 1);

	int ans = INF; 
	do
	{
		for (int i = 0; i < n; i++)
		{
			fill(v[i], v[i] + n, false);
			//for (int j = 0; j < n; j++)
			//{
			//	if (g[i][j] != '-')
			//		g[i][j] = '0';
			//}
		}

		queue<pii>q;
		for (int i = 0; i < virus.size(); i++)
		{
			if (c[i])
			{
				auto [x, y] = virus[i];
				q.push({ x,y });
				v[y][x] = true;
			}
		}
		int res = bfs(q, blank);
		if (res == -1)
			continue;
		else
			ans = min(res, ans);

		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < n; j++)
		//	{
		//		cout << g[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}
		//cout << '\n';
	} while (next_permutation(c.begin(), c.end()));

	if (ans == INF)
		cout << -1;
	else
		cout << ans;

	return 0;
}