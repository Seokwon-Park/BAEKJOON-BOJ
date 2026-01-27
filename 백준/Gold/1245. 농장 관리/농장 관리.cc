#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using hashmap = unordered_map<key, value>;

int n, m;

int dx[8] = { -1,-1,-1,0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1,1, 1, 0,-1,-1 };

int b[105][105];
bool v[105][105];

bool bfs(int x, int y)
{
	queue<pii> q;
	q.push({ x,y });
	v[y][x] = true;
	bool isTop = true;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [cx, cy] = q.front();
			q.pop();
			for (int j = 0; j < 8; j++)
			{
				int tx = cx + dx[j];
				int ty = cy + dy[j];
				if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
				if (b[ty][tx] > b[cy][cx]) isTop = false;
				if (v[ty][tx])continue;
				if (b[ty][tx] == b[cy][cx])
				{
					q.push({ tx,ty });
					v[ty][tx] = true;
				}
			}
		}
	}
	return isTop;
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
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j]) continue;
			ans += bfs(j, i);
		}
	}

	cout << ans;

	return 0;
}