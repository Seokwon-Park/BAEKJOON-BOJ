#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int n;
char b[2005][2005];
bool v[2005][2005];
int sx, sy;

int dx[8] = { -1, -1, 0, 1, 1,  1,  0, -1 };
int dy[8] = {  0,  1, 1, 1, 0, -1, -1, -1 };

int bfs()
{
	queue<pii> q;
	q.push({ sx,sy });
	v[sy][sx] = true;
	int ans = 0;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			if (i == 2) continue;
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= n || b[ty][tx] == '#' || v[ty][tx]) continue;
			ans++;
			v[ty][tx] = true;
			q.push({ tx,ty });
		}
	}
	return ans;
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
			cin >> b[i][j];
			if (b[i][j] == 'F')
			{
				sx = j;
				sy = i;
			}
		}
	}

	cout << bfs();


	return 0;
}