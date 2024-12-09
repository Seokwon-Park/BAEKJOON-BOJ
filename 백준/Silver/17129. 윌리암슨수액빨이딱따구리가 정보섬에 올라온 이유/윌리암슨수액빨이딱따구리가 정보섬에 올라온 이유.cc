#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int n, m;
char b[3005][3005];
char v[3005][3005];

queue<pii>q;

int bfs()
{
	int dist = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int j = 0; j < qs; j++)
		{
			auto [x, y] = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int tx = x + dx[i];
				int ty = y + dy[i];
				if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
				if (v[ty][tx] || b[ty][tx] == '1') continue;
				if (b[ty][tx] != '0') return dist + 1;
				q.push({ tx,ty });
				v[ty][tx] = true;
			}
		}
		dist++;
	}
	return -1;
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
			cin >> b[i][j];
			if (b[i][j] == '2')
			{
				q.push({ j,i });
				v[i][j] = true;
			}
		}
	}

	int ans = 0;
	ans = bfs();
	if (ans != -1)
	{
		cout << "TAK\n";
		cout << ans;
	}
	else
	{
		cout << "NIE";
	}
	

	return 0;
}