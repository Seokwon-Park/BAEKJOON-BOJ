#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int n, m;
int b[1005][1005];
int c[1005][1005];
bool v[1005][1005];
vector<int> ixToArea(1, 0);
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int ix = 1;

void bfs(int x, int y)
{
	queue<pii> q;
	q.push({ x,y });
	v[y][x] = true;
	int cnt = 0;
	vector<pii> save;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		save.push_back({ x,y });
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
			if (v[ty][tx] || b[ty][tx] == 1) continue;
			q.push({ tx,ty });
			v[ty][tx] = true;

		}
	}

	for (auto [x, y] : save)
	{
		c[y][x] = ix;
	}
	ix++;
	ixToArea.push_back(cnt);

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
			char ch;
			cin >> ch;
			b[i][j] = ch - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] == 0 && !v[i][j])
				bfs(j, i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] == 1)
			{
				vector<bool> isAdded(ix, false);
				int sum = 1;
				for (int k = 0; k < 4; k++)
				{
					int tx = j + dx[k];
					int ty = i + dy[k];
					if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
					if (isAdded[c[ty][tx]]) continue;
					sum += ixToArea[c[ty][tx]];
					isAdded[c[ty][tx]] = true;
				}
				b[i][j] = sum % 10;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << b[i][j];
		}
		cout << '\n';
	}
	
	return 0;
}
