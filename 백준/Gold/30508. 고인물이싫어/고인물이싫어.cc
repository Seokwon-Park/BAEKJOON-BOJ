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
//int nowater[1005][1005];
int sum[1005][1005];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int n, m;


void bfs(vector<pii> input)
{
	queue<pii> q;
	for (int i = 0; i < input.size(); i++)
	{
		auto [r, c] = input[i];
		q.push({c,r});
		v[r][c] = 1;
	}

	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx <= 0 || ty <= 0 || tx > m || ty > n) continue;
			if (v[ty][tx] || b[ty][tx] < b[y][x]) continue;
			q.push({ tx,ty });
			v[ty][tx] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int h, w;
	cin >> h >> w;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> b[i][j];
		}
	}

	int k;
	cin >> k;
	vector<pii> input;
	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;
		input.push_back({ r,c });
	}

	bfs(input);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + v[i][j];
		}
	}

	int ans = 0;
	for (int i = h; i <= n; i++)
	{
		for (int j = w; j <= m; j++)
		{
			int res = sum[i][j] - sum[i - h][j] - sum[i][j - w] + sum[i - h][j - w];
			if (res == h*w)
			{
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}