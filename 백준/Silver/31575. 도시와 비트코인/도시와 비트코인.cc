#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int b[305][305];
int v[305][305];


int n, m;
int dx[2] = { 1 , 0 };
int dy[2] = { 0, 1 };

bool bfs()
{
	queue<pii> q;
	q.push({ 0,0 });
	v[0][0] = 1;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		if (x == m - 1 && y == n - 1) return true;
		for (int i = 0; i < 2; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx >= m || ty >= n || b[ty][tx] == 0 || v[ty][tx]) continue;
			q.push({ tx,ty });
			v[ty][tx] = 1;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	cout << (bfs() ? "Yes" : "No");


	return 0;
}